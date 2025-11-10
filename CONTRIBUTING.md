# Contributing to MinimalOS

Thank you for your interest in contributing to MinimalOS! This document provides guidelines and instructions for contributing.

## Code of Conduct

- Be respectful and inclusive
- Provide constructive feedback
- Focus on what is best for the community
- Show empathy towards other community members

## How to Contribute

### Reporting Bugs

Before creating bug reports, please check existing issues. When creating a bug report, include:

- **Clear title and description**
- **Steps to reproduce** the issue
- **Expected behavior** vs actual behavior
- **System information** (OS, GCC version, QEMU version)
- **Error messages** or screenshots if applicable

### Suggesting Enhancements

Enhancement suggestions are tracked as GitHub issues. When creating an enhancement suggestion, include:

- **Clear title and description**
- **Use case** - why is this enhancement useful?
- **Possible implementation** - if you have ideas
- **Examples** from other projects if applicable

### Pull Requests

1. **Fork the repository** and create your branch from `main`
2. **Make your changes** following the coding standards below
3. **Test your changes** thoroughly
4. **Update documentation** if needed
5. **Commit with clear messages** describing what and why
6. **Submit a pull request**

## Development Setup

### Prerequisites

```bash
# Ubuntu/Debian
sudo apt-get install build-essential nasm qemu-system-x86 gdb

# macOS
brew install nasm qemu i686-elf-gcc
```

### Building

```bash
make clean
make
make run
```

### Testing

```bash
# Run in QEMU
make run

# Run with debugging
qemu-system-i386 -kernel kernel.bin -s -S
# In another terminal:
gdb kernel.bin
(gdb) target remote localhost:1234
```

## Coding Standards

### C Code Style

- **Indentation**: 4 spaces (no tabs)
- **Line length**: Maximum 100 characters
- **Braces**: K&R style
  ```c
  if (condition) {
      // code
  } else {
      // code
  }
  ```
- **Naming**:
  - Functions: `snake_case`
  - Variables: `snake_case`
  - Constants: `UPPER_CASE`
  - Types: `snake_case_t`

### Documentation

- **Every function** must have a comment block:
  ```c
  /**
   * function_name - Brief description
   * @param1: Description of param1
   * @param2: Description of param2
   * 
   * Detailed description if needed.
   * 
   * Returns: Description of return value
   */
  ```
- **Complex code** should have inline comments
- **Update README.md** if adding features

### Assembly Code Style

- **Comments**: Explain what each section does
- **Labels**: Descriptive names
- **Alignment**: Use `align` directives appropriately

### Commit Messages

Follow conventional commits format:

```
type(scope): subject

body (optional)

footer (optional)
```

Types:
- `feat`: New feature
- `fix`: Bug fix
- `docs`: Documentation changes
- `style`: Code style changes (formatting)
- `refactor`: Code refactoring
- `test`: Adding tests
- `chore`: Maintenance tasks

Examples:
```
feat(shell): add ls command to list files

fix(memory): correct heap overflow in kmalloc

docs(readme): update build instructions for macOS
```

## Project Areas

### Easy Contributions

Good for first-time contributors:

- Documentation improvements
- Adding comments to code
- Fixing typos
- Adding examples
- Improving error messages

### Medium Difficulty

- Adding new shell commands
- Improving VGA driver (colors, cursor)
- Enhancing memory allocator
- Adding utility functions

### Advanced

- Implementing keyboard driver
- Adding timer interrupts
- File system implementation
- Network stack
- Multi-core support

## Testing Guidelines

### Before Submitting

- [ ] Code compiles without warnings
- [ ] Kernel boots successfully in QEMU
- [ ] All existing features still work
- [ ] New features are tested
- [ ] Documentation is updated
- [ ] Code follows style guidelines

### Test Checklist

```bash
# Build test
make clean && make

# Boot test
make run
# Verify: Kernel boots and shows "Hello, Kernel!"

# Feature test
# Test your specific feature works as expected

# Regression test
# Verify existing commands still work:
# - help
# - echo
# - clear
```

## Documentation

### What to Document

- New features and how to use them
- API changes
- Configuration options
- Build requirements
- Known issues or limitations

### Where to Document

- **README.md**: User-facing features
- **Code comments**: Implementation details
- **ARCHITECTURE.md**: System design
- **Inline comments**: Complex algorithms

## Review Process

1. **Automated checks** run on PR submission
2. **Code review** by maintainers
3. **Testing** in various environments
4. **Approval** and merge

### Review Criteria

- Code quality and style
- Test coverage
- Documentation completeness
- Performance impact
- Security considerations

## Getting Help

- **GitHub Issues**: For bugs and features
- **Discussions**: For questions and ideas
- **Email**: [maintainer email]

## Recognition

Contributors will be:
- Listed in CONTRIBUTORS.md
- Mentioned in release notes
- Credited in commit history

## License

By contributing, you agree that your contributions will be licensed under the MIT License.

---

Thank you for contributing to MinimalOS! 🎉
