package main

import (
	"fmt"
	"os"
	"strconv"

	"complex-init-example/config" // 导入 config 包
	"complex-init-example/log"    // 导入 log 包
)

func main() {
	cfg := config.GetConfig() // 获取配置
	logger := log.GetLogger() // 获取日志记录器

	logger.Info("Application starting...")
	logger.Debug(fmt.Sprintf("Debug log enabled, current config: %+v", cfg)) // 只有当日志级别为 DEBUG 或更低时才会输出

	fmt.Printf("App Name: %s\n", cfg.AppName)
	fmt.Printf("Server Host: %s\n", cfg.ServerHost)
	fmt.Printf("Server Port: %d\n", cfg.ServerPort)
	fmt.Printf("Log Level: %s\n", cfg.LogLevel)

	// 模拟应用程序运行
	fmt.Println("\n--- Application is running ---")
	fmt.Println("You can access the application at http://" + cfg.ServerHost + ":" + strconv.Itoa(cfg.ServerPort))

	logger.Info("Application started successfully.")

	// 模拟一些错误情况
	if cfg.LogLevel == "DEBUG" {
		logger.Warn("This is a warning message for demonstration.")
		logger.Error("This is an error message for demonstration.")
	}

	// 退出程序
	os.Exit(0)
}

// main 包的 init 函数
func init() {
	fmt.Println("Main package init function is running.")
	// 在 main 包的 init 函数中，我们可能进行一些与 main 包相关的初始化操作
	// 例如，检查运行环境，设置命令行参数等等。
	// 在此示例中，我们为了演示目的，仅打印一条消息。
}
