// Music control
const bgm = document.getElementById('bgm');
const musicToggle = document.querySelector('.music-toggle');
let musicEnabled = true;

musicToggle.addEventListener('click', () => {
    musicEnabled = !musicEnabled;
    musicToggle.textContent = musicEnabled ? '🎵 背景音乐' : '🎵 关闭音乐';
    if (musicEnabled) {
        bgm.play();
    } else {
        bgm.pause();
    }
});

// Game elements
const boardElement = document.querySelector('.board');
const statusElement = document.querySelector('.status');
const restartButton = document.querySelector('.restart');

// Sound effects
const placeSound = new Audio('https://assets.mixkit.co/active_storage/sfx/2311/2311-preview.mp3');
const winSound = new Audio('https://assets.mixkit.co/active_storage/sfx/1063/1063-preview.mp3');

let board = [];
let currentPlayer = 'black';
let gameOver = false;
let animationInProgress = false;

// Initialize the game board
function initBoard() {
    board = Array(15).fill().map(() => Array(15).fill(null));
    boardElement.innerHTML = '';
    
    for (let row = 0; row < 15; row++) {
        for (let col = 0; col < 15; col++) {
            const cell = document.createElement('div');
            cell.dataset.row = row;
            cell.dataset.col = col;
            cell.addEventListener('click', handleCellClick);
            boardElement.appendChild(cell);
        }
    }
    
    statusElement.classList.remove('winner');
    updateStatus();
    animationInProgress = false;
}

// Handle cell click
function handleCellClick(e) {
    if (gameOver || animationInProgress) return;
    
    const row = parseInt(e.target.dataset.row);
    const col = parseInt(e.target.dataset.col);
    
    if (board[row][col] !== null) return;
    
    animationInProgress = true;
    placeSound.play();
    
    // Animate stone placement
    e.target.classList.add(currentPlayer);
    e.target.style.transform = 'scale(1.2)';
    setTimeout(() => {
        e.target.style.transform = 'scale(1)';
    }, 200);
    
    board[row][col] = currentPlayer;
    
    if (checkWin(row, col)) {
        gameOver = true;
        statusElement.classList.add('winner');
        statusElement.textContent = `${currentPlayer.toUpperCase()} wins!`;
        winSound.play();
        
        // Animate winning stones
        const winningStones = getWinningStones(row, col);
        animateWinningStones(winningStones);
        return;
    }
    
    currentPlayer = currentPlayer === 'black' ? 'white' : 'black';
    updateStatus();
    animationInProgress = false;
}

// Get winning stones positions
function getWinningStones(row, col) {
    const directions = [
        [1, 0],  // vertical
        [0, 1],  // horizontal
        [1, 1],  // diagonal down-right
        [1, -1]  // diagonal down-left
    ];

    for (const [dx, dy] of directions) {
        let stones = [{row, col}];
        
        // Check in positive direction
        let x = row + dx;
        let y = col + dy;
        while (x >= 0 && x < 15 && y >= 0 && y < 15 && 
               board[x][y] === currentPlayer) {
            stones.push({row: x, col: y});
            x += dx;
            y += dy;
        }
        
        // Check in negative direction
        x = row - dx;
        y = col - dy;
        while (x >= 0 && x < 15 && y >= 0 && y < 15 && 
               board[x][y] === currentPlayer) {
            stones.push({row: x, col: y});
            x -= dx;
            y -= dy;
        }
        
        if (stones.length >= 5) {
            return stones;
        }
    }
    
    return [];
}

// Animate winning stones
function animateWinningStones(stones) {
    stones.forEach((stone, index) => {
        const cell = document.querySelector(`[data-row="${stone.row}"][data-col="${stone.col}"]`);
        setTimeout(() => {
            cell.style.transform = 'scale(1.2)';
            cell.style.transition = 'transform 0.2s ease';
            setTimeout(() => {
                cell.style.transform = 'scale(1)';
            }, 200);
        }, index * 100);
    });
}

// Check for win condition
function checkWin(row, col) {
    const directions = [
        [1, 0],  // vertical
        [0, 1],  // horizontal
        [1, 1],  // diagonal down-right
        [1, -1]  // diagonal down-left
    ];

    for (const [dx, dy] of directions) {
        let count = 1;
        
        // Check in positive direction
        let x = row + dx;
        let y = col + dy;
        while (x >= 0 && x < 15 && y >= 0 && y < 15 && 
               board[x][y] === currentPlayer) {
            count++;
            x += dx;
            y += dy;
        }
        
        // Check in negative direction
        x = row - dx;
        y = col - dy;
        while (x >= 0 && x < 15 && y >= 0 && y < 15 && 
               board[x][y] === currentPlayer) {
            count++;
            x -= dx;
            y -= dy;
        }
        
        if (count >= 5) return true;
    }
    
    return false;
}

// Update game status
function updateStatus() {
    statusElement.style.opacity = 0;
    setTimeout(() => {
        statusElement.textContent = `${currentPlayer.toUpperCase()}'s turn`;
        statusElement.style.opacity = 1;
    }, 200);
}

// Restart game
restartButton.addEventListener('click', () => {
    gameOver = false;
    currentPlayer = 'black';
    initBoard();
});

// Initialize game on load
initBoard();
