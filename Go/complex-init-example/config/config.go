package config

import (
	"fmt"
	"os"
	"strconv"
	"sync"
)

// AppConfig 结构体用于存储应用程序的配置信息
type AppConfig struct {
	AppName    string
	ServerHost string
	ServerPort int
	LogLevel   string
}

var (
	config     *AppConfig
	configOnce sync.Once
)

// loadDefaults 加载默认配置
func loadDefaults() *AppConfig {
	return &AppConfig{
		AppName:    "ComplexApp",
		ServerHost: "localhost",
		ServerPort: 8080,
		LogLevel:   "INFO",
	}
}

// loadFromEnv 从环境变量加载配置，并覆盖现有配置
func loadFromEnv(cfg *AppConfig) *AppConfig {
	if appName := os.Getenv("APP_NAME"); appName != "" {
		cfg.AppName = appName
	}
	if serverHost := os.Getenv("SERVER_HOST"); serverHost != "" {
		cfg.ServerHost = serverHost
	}
	if serverPortStr := os.Getenv("SERVER_PORT"); serverPortStr != "" {
		if serverPort, err := strconv.Atoi(serverPortStr); err == nil {
			cfg.ServerPort = serverPort
		} else {
			fmt.Fprintf(os.Stderr, "WARN: Invalid SERVER_PORT value '%s', using default port %d\n", serverPortStr, cfg.ServerPort)
		}
	}
	if logLevel := os.Getenv("LOG_LEVEL"); logLevel != "" {
		cfg.LogLevel = logLevel
	}
	return cfg
}

// InitConfig 初始化配置，使用 sync.Once 保证只执行一次
func InitConfig() *AppConfig {
	configOnce.Do(func() {
		cfg := loadDefaults()
		cfg = loadFromEnv(cfg)
		config = cfg
		fmt.Println("Config initialized.")         // 显式提示配置初始化完成
		fmt.Printf("Loaded Config: %+v\n", config) // 打印加载的配置信息
	})
	return config
}

// GetConfig 获取配置实例
func GetConfig() *AppConfig {
	if config == nil {
		// 在并发安全的情况下，即使 InitConfig 还没被显式调用，GetConfig 也能初始化配置
		return InitConfig()
	}
	return config
}

// init 函数在包被导入时自动执行，在这里我们调用 InitConfig 进行初始化
func init() {
	InitConfig()
}
