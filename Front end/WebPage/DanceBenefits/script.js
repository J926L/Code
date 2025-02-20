// 页面加载动画
document.addEventListener('DOMContentLoaded', () => {
    const sections = document.querySelectorAll('section');
    sections.forEach((section, index) => {
        setTimeout(() => {
            section.style.opacity = 1;
            section.style.transform = 'translateY(0)';
        }, index * 200);
    });

    // 平滑滚动效果
    const buttons = document.querySelectorAll('button');
    buttons.forEach(button => {
        button.addEventListener('click', () => {
            document.body.style.opacity = 0;
            setTimeout(() => {
                document.body.style.opacity = 1;
            }, 300);
        });
    });
});

// 返回按钮效果
const backButtons = document.querySelectorAll('.back-btn');
backButtons.forEach(button => {
    button.addEventListener('click', (e) => {
        e.preventDefault();
        document.body.style.opacity = 0;
        setTimeout(() => {
            window.location.href = button.href;
        }, 300);
    });
});

// 添加CSS动画
const style = document.createElement('style');
style.textContent = `
    @keyframes bounce {
        0%, 100% { transform: scale(1); }
        50% { transform: scale(1.1); }
    }
`;
document.head.appendChild(style);