# Inventory Management System

[![Open Source](https://img.shields.io/badge/Open%20Source-%E2%9D%A4-red)](https://github.com/Da8K7Oul/Inventory)
[![Free Software](https://img.shields.io/badge/Free-Software-green)](https://github.com/Da8K7Oul/Inventory)
[![No Monetization](https://img.shields.io/badge/No-Monetization-blue)](https://github.com/Da8K7Oul/Inventory)

A simple yet effective **open source** inventory management system created to help manage shop inventory efficiently. This project is completely free and should remain free for everyone.

## 📋 Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Project Structure](#project-structure)
- [Quick Start](#quick-start)
- [Installation](#installation)
- [Usage](#usage)
- [Development](#development)
- [Contributing](#contributing)
- [License](#license)

## 🎯 Overview

This is a plain inventory system developed to help manage retail shop operations. The project provides both ready-to-use executable files and complete source code for developers who want to customize or extend the functionality.

## ✨ Features

- **Inventory Tracking**: Monitor stock levels and product details
- **Easy-to-Use Interface**: Simple console-based interface for quick operations
- **Product Management**: Add, update, and remove products from inventory
- **Stock Monitoring**: Keep track of available quantities
- **Cross-Platform**: Works on Windows, Linux, and macOS (with compilation)

## 📁 Project Structure

The repository is organized into two main directories:

```
Inventory/
├── AppV3/              # Ready-to-use executable files
│   └── [Executable files - Download and run directly]
│
└── inventoryv2/        # Source code
    └── [Main C++ code files]
```

### Directory Details

- **AppV3**: Contains pre-compiled executable files ready for immediate use. Simply download and run without any setup required.
  
- **inventoryv2**: Contains the main source code written in C++ and Python. Use this directory if you want to:
  - Understand how the system works
  - Modify the code for custom requirements
  - Compile for different platforms
  - Contribute to the project

## 🚀 Quick Start

### For Users (Quick Setup)

1. Navigate to the [AppV3](./AppV3) directory
2. Download the appropriate executable for your operating system
3. Run the executable file
4. Start managing your inventory!

### For Developers

1. Clone the repository:
   ```bash
   git clone https://github.com/Da8K7Oul/Inventory.git
   cd Inventory
   ```

2. Navigate to the source code directory:
   ```bash
   cd inventoryv2
   ```

3. Compile the code (instructions below)

## 🛠️ Installation

### Prerequisites

- **For Users**: No prerequisites needed - just download and run from AppV3
- **For Developers**:
  - C++ Compiler (GCC, Clang, or MSVC)
  - Python 3.x (for Python components)
  - Make or CMake (optional, for build automation)

### Compiling from Source

#### On Windows
```bash
g++ main.cpp -o inventory.exe
```

#### On Linux/macOS
```bash
g++ main.cpp -o inventory
chmod +x inventory
./inventory
```

## 💻 Usage

### Basic Operations

1. **Starting the Application**
   - Run the executable from AppV3, or
   - Compile and run from source

2. **Managing Inventory**
   - Follow the on-screen menu prompts
   - Select options to add, view, update, or delete inventory items

3. **Data Storage**
   - Inventory data is stored locally
   - Ensure you have write permissions in the installation directory

### Common Tasks

- **Add New Product**: Select the "Add Product" option and enter product details
- **View Inventory**: Display all current stock items
- **Update Stock**: Modify quantities or product information
- **Remove Product**: Delete items from the inventory database

## 🔧 Development

### Technology Stack

- **Primary Language**: C++ (86.0%)
- **Secondary Language**: Python (14.0%)

### Code Structure

The `inventoryv2` directory contains the modular source code:
- Core inventory management logic
- Data persistence layer
- User interface components
- Utility functions

### Building and Testing

```bash
# Navigate to source directory
cd inventoryv2

# Compile
g++ -o inventory main.cpp

# Run
./inventory
```

## 🤝 Contributing

Contributions are welcome! Here's how you can help:

1. **Fork the repository**
2. **Create a feature branch**
   ```bash
   git checkout -b feature/AmazingFeature
   ```
3. **Commit your changes**
   ```bash
   git commit -m 'Add some AmazingFeature'
   ```
4. **Push to the branch**
   ```bash
   git push origin feature/AmazingFeature
   ```
5. **Open a Pull Request**

### Contribution Guidelines

- Follow existing code style and conventions
- Comment your code where necessary
- Test thoroughly before submitting
- Update documentation for new features

## 📝 License

This project is **open source** and **free to use**. 

- ✅ Free for personal use
- ✅ Free for educational use
- ✅ Free for commercial use
- ✅ Modify and distribute freely
- ❌ **Not for monetization** - This project should remain free and accessible to everyone

This software is provided "as is", without warranty of any kind. Feel free to use, modify, and share, but please keep it free and open for the community.

## 👤 Author

**Syed Mahmood Taha** ([@Da8K7Oul](https://github.com/Da8K7Oul))

## 🙏 Acknowledgments

- Created to help manage uncle's shop operations
- Built with simplicity and efficiency in mind
- Thanks to all contributors and users

## 💡 Open Source Philosophy

This project was created to help small shop owners manage their inventory without expensive software costs. It will **always remain free and open source**. If you find it useful:

- Share it with others who might benefit
- Contribute improvements back to the community
- Keep the spirit of free, accessible software alive

**Please do not monetize this project.** Help us keep quality software free for everyone, especially small business owners who need it most.

## 📞 Support

If you encounter any issues or have questions:
- Open an [issue](https://github.com/Da8K7Oul/Inventory/issues)
- Contact the repository owner

---

**Note**: This is a practical inventory management solution designed for small to medium retail operations. For enterprise-level solutions, additional features and scalability considerations may be required.

## 🔄 Updates

Check the [commits history](https://github.com/Da8K7Oul/Inventory/commits/main/) for the latest changes and improvements.

---
**Star this repository** ⭐ if you find it helpful!
