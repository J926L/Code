// Constants for Chinese calendar calculations
const HEAVENLY_STEMS = ['甲', '乙', '丙', '丁', '戊', '己', '庚', '辛', '壬', '癸'];
const EARTHLY_BRANCHES = ['子', '丑', '寅', '卯', '辰', '巳', '午', '未', '申', '酉', '戌', '亥'];
const ELEMENTS = {
    '甲': '木', '乙': '木',
    '丙': '火', '丁': '火',
    '戊': '土', '己': '土',
    '庚': '金', '辛': '金',
    '壬': '水', '癸': '水'
};

// Each branch's hidden elements
const BRANCH_ELEMENTS = {
    '子': ['水'],
    '丑': ['土', '土', '金'],
    '寅': ['木', '木', '火'],
    '卯': ['木'],
    '辰': ['土', '土', '水'],
    '巳': ['火', '火', '土'],
    '午': ['火'],
    '未': ['土', '土', '火'],
    '申': ['金', '金', '水'],
    '酉': ['金'],
    '戌': ['土', '土', '火'],
    '亥': ['水', '水', '木']
};

// Calculate year pillar
function getYearPillar(year) {
    const heavenlyStemIndex = (year - 4) % 10;
    const earthlyBranchIndex = (year - 4) % 12;
    return {
        stem: HEAVENLY_STEMS[heavenlyStemIndex],
        branch: EARTHLY_BRANCHES[earthlyBranchIndex]
    };
}

// Calculate month pillar
function getMonthPillar(year, month) {
    const yearStemIndex = (year - 4) % 10;
    const baseMonth = (month + 2) % 12;
    const monthStemIndex = (yearStemIndex * 2 + baseMonth) % 10;
    return {
        stem: HEAVENLY_STEMS[monthStemIndex],
        branch: EARTHLY_BRANCHES[baseMonth]
    };
}

// Calculate day pillar
function getDayPillar(year, month, day) {
    // This is a simplified calculation for demonstration
    // In a real implementation, you would need a more accurate algorithm
    const baseDate = new Date(1900, 0, 1);
    const targetDate = new Date(year, month - 1, day);
    const daysDiff = Math.floor((targetDate - baseDate) / (1000 * 60 * 60 * 24));
    const stemIndex = (daysDiff + 10) % 10;
    const branchIndex = (daysDiff + 12) % 12;
    return {
        stem: HEAVENLY_STEMS[stemIndex],
        branch: EARTHLY_BRANCHES[branchIndex]
    };
}

// Calculate hour pillar
function getHourPillar(dayStemIndex, hour) {
    const [startHour] = hour.split(',').map(Number);
    const branchIndex = Math.floor(((startHour + 1) % 24) / 2);
    const stemIndex = (dayStemIndex * 2 + branchIndex) % 10;
    return {
        stem: HEAVENLY_STEMS[stemIndex],
        branch: EARTHLY_BRANCHES[branchIndex]
    };
}

// Calculate five elements distribution
function calculateElements(yearPillar, monthPillar, dayPillar, hourPillar) {
    const elements = { '木': 0, '火': 0, '土': 0, '金': 0, '水': 0 };
    
    // Add elements from heavenly stems
    [yearPillar, monthPillar, dayPillar, hourPillar].forEach(pillar => {
        elements[ELEMENTS[pillar.stem]]++;
    });

    // Add elements from earthly branches
    [yearPillar, monthPillar, dayPillar, hourPillar].forEach(pillar => {
        BRANCH_ELEMENTS[pillar.branch].forEach(element => {
            elements[element]++;
        });
    });

    return elements;
}

// Event Listeners
document.addEventListener('DOMContentLoaded', () => {
    const form = document.getElementById('baziForm');
    
    form.addEventListener('submit', (e) => {
        e.preventDefault();
        
        const year = parseInt(document.getElementById('year').value);
        const month = parseInt(document.getElementById('month').value);
        const day = parseInt(document.getElementById('day').value);
        const hour = document.getElementById('hour').value;

        // Calculate pillars
        const yearPillar = getYearPillar(year);
        const monthPillar = getMonthPillar(year, month);
        const dayPillar = getDayPillar(year, month, day);
        const hourPillar = getHourPillar((year - 4) % 10, hour);

        // Update UI with results
        document.querySelector('#yearPillar .heavenly-stem').textContent = yearPillar.stem;
        document.querySelector('#yearPillar .earthly-branch').textContent = yearPillar.branch;
        
        document.querySelector('#monthPillar .heavenly-stem').textContent = monthPillar.stem;
        document.querySelector('#monthPillar .earthly-branch').textContent = monthPillar.branch;
        
        document.querySelector('#dayPillar .heavenly-stem').textContent = dayPillar.stem;
        document.querySelector('#dayPillar .earthly-branch').textContent = dayPillar.branch;
        
        document.querySelector('#hourPillar .heavenly-stem').textContent = hourPillar.stem;
        document.querySelector('#hourPillar .earthly-branch').textContent = hourPillar.branch;

        // Calculate and display elements analysis
        const elements = calculateElements(yearPillar, monthPillar, dayPillar, hourPillar);
        const elementsChart = document.getElementById('elementsChart');
        elementsChart.innerHTML = Object.entries(elements)
            .map(([element, count]) => `<div>${element}: ${count}</div>`)
            .join('');

        // Show results
        document.getElementById('result').classList.remove('hidden');
    });
});
