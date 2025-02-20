package log

import (
	"fmt"
	"sync"
	"time"

	"complex-init-example/config" // 导入 config 包
)

type Logger struct {
	logLevel string
}

var (
	logger     *Logger
	loggerOnce sync.Once
)

// NewLogger 创建一个新的 Logger 实例
func NewLogger(logLevel string) *Logger {
	return &Logger{logLevel: logLevel}
}

// InitLogger 初始化 Logger，使用 sync.Once 保证只执行一次
func InitLogger() *Logger {
	loggerOnce.Do(func() {
		cfg := config.GetConfig() // 获取配置信息
		level := cfg.LogLevel
		logger = NewLogger(level)
		fmt.Printf("Logger initialized with level: %s\n", level) // 提示日志系统初始化完成
	})
	return logger
}

// GetLogger 获取 Logger 实例
func GetLogger() *Logger {
	if logger == nil {
		// 确保在获取 Logger 前已被初始化
		return InitLogger()
	}
	return logger
}

func (l *Logger) Log(level string, message string) {
	// 简单的日志输出，实际应用中可以更复杂
	logLevels := map[string]int{"DEBUG": 0, "INFO": 1, "WARN": 2, "ERROR": 3}
	currentLevel, ok := logLevels[l.logLevel]
	messageLevel, messageOk := logLevels[level]

	if ok && messageOk && messageLevel >= currentLevel {
		timestamp := time.Now().Format(time.RFC3339)
		fmt.Printf("%s [%s] %s\n", timestamp, level, message)
	}
}

func (l *Logger) Info(message string) {
	l.Log("INFO", message)
}

func (l *Logger) Warn(message string) {
	l.Log("WARN", message)
}

func (l *Logger) Error(message string) {
	l.Log("ERROR", message)
}

func (l *Logger) Debug(message string) {
	l.Log("DEBUG", message)
}

// init 函数在包被导入时自动执行，初始化 Logger
func init() {
	InitLogger()
}
