# MyFind Project

## Overview

MyFind is a command-line tool written in C that mimics the functionality of the `find` command in a Linux environment. It allows users to search for files and directories based on various search criteria like name, type, size, modification time, etc. The tool aims to be a lightweight, customizable alternative for file searching.

This project is a great educational exercise in understanding system programming, file manipulation, and parsing in C. Additionally, it includes unit tests written with `pytest` to ensure correct parsing and functionality of the implementation.

## Features

- **File Search**: Search for files and directories in a specified path.
- **Search Filters**: Supports filtering by name, type (file, directory), size, and modification time.
- **Customizable**: Easily extendable for additional filters and features.
- **Performance**: Efficient traversal of directories with careful memory management.

## Technologies

- **Language**: C
- **Testing Framework**: `pytest` for unit testing (Python bindings used to ensure correct parsing).
