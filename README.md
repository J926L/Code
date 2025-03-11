```bash
sudo apt update && sudo apt upgrade -y
```
```bash
python -m pip install
python -m pip install --upgrade pip
```
```bash
gcc -o C/hello C/hello.c && ./C/hello
gcc -o C/prime C/Prime.c && ./C/prime
```

To set up Rust on Ubuntu and create a program using Cargo, follow these steps:

### 1. Install Rust
First, install Rust by using `rustup`, the official Rust installer.

Open a terminal and run the following command:

```bash
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
```

This will download and install `rustup`, which installs the Rust toolchain. Follow the on-screen instructions, and the installer will prompt you to add Rust to your system’s `PATH`.

If you encounter any permission issues, use `sudo` to install, or run the installer as a regular user with appropriate permissions.

### 2. Configure the Rust Environment
After installation, you need to configure the environment:

```bash
source $HOME/.cargo/env
```

To make this permanent, you can add the above line to your shell configuration file, e.g., `~/.bashrc` or `~/.zshrc`, depending on your shell.

```bash
echo 'source $HOME/.cargo/env' >> ~/.bashrc
```

Reload the configuration file:

```bash
source ~/.bashrc
```

### 3. Verify the Installation
Check that Rust is installed correctly:

```bash
rustc --version
```

You should see an output like:

```bash
rustc 1.x.x (xxxxxx 202x-xx-xx)
```

Also, verify Cargo, the Rust package manager:

```bash
cargo --version
```

### 4. Create a New Rust Project
Now, you can use Cargo to create a new Rust project. In your terminal, navigate to the directory where you want to store your project and run:

```bash
cargo new hello
cd hello
```

This will create a new directory called `hello` with the following structure:

```
hello
├── Cargo.toml
└── src
    └── main.rs
```

- `Cargo.toml` is the configuration file for your project.
- `src/main.rs` is where your main program code goes.

### 5. Write a Simple Program
Open the `src/main.rs` file and replace the contents with a simple “Hello, world!” program:

```rust
fn main() {
    println!("Hello, world!");
}
```

### 6. Build and Run the Project
In your terminal, run the following command to build and run the program:

```bash
cargo run
```

This will compile the program and output:

```
   Compiling hello v0.1.0 (/path/to/hello)
    Finished dev [unoptimized + debuginfo] target(s) in 2.11s
     Running `target/debug/hello`
Hello, world!
```

### 7. Summary
- Install Rust using `rustup`.
- Create a new project with `cargo new`.
- Write your code in `src/main.rs`.
- Build and run your project with `cargo run`.

That's it! You've successfully set up Rust and created your first program using Cargo on Ubuntu.