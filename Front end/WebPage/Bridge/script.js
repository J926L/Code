const canvas = document.getElementById('game-canvas');
const ctx = canvas.getContext('2d');

// 牌桌尺寸
const tableWidth = 800;
const tableHeight = 600;

// 玩家位置
const positions = {
    north: { x: tableWidth / 2 - 50, y: 50 },
    east: { x: tableWidth - 150, y: tableHeight / 2 - 50 },
    south: { x: tableWidth / 2 - 50, y: tableHeight - 150 },
    west: { x: 50, y: tableHeight / 2 - 50 }
};

// 初始化游戏
function init() {
    // 绘制牌桌背景
    ctx.fillStyle = '#4CAF50';
    ctx.fillRect(0, 0, tableWidth, tableHeight);

    // 绘制中心区域
    ctx.fillStyle = '#388E3C';
    ctx.fillRect(200, 150, 400, 300);

    // 绘制玩家位置标记
    ctx.fillStyle = '#fff';
    ctx.font = '20px Arial';
    ctx.textAlign = 'center';
    
    ctx.fillText('北', positions.north.x + 50, positions.north.y + 30);
    ctx.fillText('东', positions.east.x + 50, positions.east.y + 30);
    ctx.fillText('南', positions.south.x + 50, positions.south.y + 30);
    ctx.fillText('西', positions.west.x + 50, positions.west.y + 30);
}

// 启动游戏
init();