# Security Policy

## Supported Versions

Currently supported versions of MinimalOS:

| Version | Supported          |
| ------- | ------------------ |
| 1.0.x   | :white_check_mark: |

## Reporting a Vulnerability

We take security seriously. If you discover a security vulnerability in MinimalOS, please report it responsibly.

### How to Report

**Please do NOT create a public GitHub issue for security vulnerabilities.**

Instead, please email security details to:
- **Email**: your.email@example.com
- **Subject**: [SECURITY] Brief description

### What to Include

Please include the following information:

1. **Description** of the vulnerability
2. **Steps to reproduce** the issue
3. **Potential impact** of the vulnerability
4. **Suggested fix** (if you have one)
5. **Your contact information** for follow-up

### Response Timeline

- **Initial Response**: Within 48 hours
- **Status Update**: Within 7 days
- **Fix Timeline**: Depends on severity
  - Critical: 1-7 days
  - High: 7-14 days
  - Medium: 14-30 days
  - Low: 30-90 days

### Disclosure Policy

- We will acknowledge your report within 48 hours
- We will provide regular updates on our progress
- We will notify you when the vulnerability is fixed
- We will credit you in the security advisory (unless you prefer to remain anonymous)

### Security Best Practices

When using MinimalOS:

1. **Always use the latest version**
2. **Review code** before running on production systems
3. **Test in isolated environments** (QEMU/VirtualBox)
4. **Keep dependencies updated** (GCC, NASM, QEMU)
5. **Report issues** promptly

### Known Limitations

MinimalOS is an educational project and has the following known limitations:

- **No user authentication** - All code runs in kernel mode
- **No memory protection** - Simple memory allocator without guards
- **No input validation** - Shell commands are not sanitized
- **No encryption** - All data is stored in plain text
- **No network security** - No network stack implemented yet

### Security Features

Current security features:

- ✅ Freestanding compilation (no standard library dependencies)
- ✅ Stack protection disabled (for kernel development)
- ✅ Position-independent code disabled (for predictable memory layout)

### Future Security Enhancements

Planned security improvements:

- [ ] User mode and privilege separation
- [ ] Memory protection (page-level permissions)
- [ ] Input validation and sanitization
- [ ] Secure boot support
- [ ] Address Space Layout Randomization (ASLR)
- [ ] Stack canaries
- [ ] Bounds checking

## Security Advisories

Security advisories will be published at:
- GitHub Security Advisories
- SECURITY_ADVISORIES.md file
- Release notes

## Hall of Fame

Security researchers who have responsibly disclosed vulnerabilities:

<!-- Will be updated as vulnerabilities are reported and fixed -->

---

Thank you for helping keep MinimalOS secure!
