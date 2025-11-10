# GitHub Repository Setup Guide

Complete guide to setting up your MinimalOS repository on GitHub.

## Step 1: Create GitHub Repository

1. Go to https://github.com/new
2. Fill in repository details:
   - **Repository name**: `MinimalOS`
   - **Description**: `A minimal x86 operating system kernel built from scratch in C and Assembly`
   - **Visibility**: Public (recommended for open source)
   - **Initialize**: Don't initialize with README (we already have one)
3. Click "Create repository"

## Step 2: Prepare Local Repository

```bash
# Navigate to your project directory
cd "C:\Users\ME\Desktop\Chetan\Project - 1"

# Or in WSL
cd '/mnt/c/Users/ME/Desktop/Chetan/Project - 1'

# Initialize git repository
git init

# Add all files
git add .

# Create initial commit
git commit -m "Initial commit: MinimalOS v1.0.0

- Multiboot bootloader
- 32-bit protected mode kernel
- Memory management with 4MB heap
- Round-robin task scheduler
- VGA text mode driver
- Interactive shell with commands
- Complete documentation"
```

## Step 3: Connect to GitHub

```bash
# Add remote repository
git remote add origin https://github.com/chetanbhargavv/MinimalOS.git

# Push to GitHub
git branch -M main
git push -u origin main
```

## Step 4: Configure Repository Settings

### About Section

1. Go to your repository on GitHub
2. Click the gear icon next to "About"
3. Add:
   - **Description**: `A minimal x86 operating system kernel built from scratch in C and Assembly`
   - **Website**: (optional)
   - **Topics**: `operating-system`, `kernel`, `x86`, `osdev`, `c`, `assembly`, `education`, `multiboot`, `qemu`
4. Check: ✅ Releases, ✅ Packages

### Repository Settings

1. Go to Settings tab
2. **General**:
   - Features: Enable Issues, Discussions, Projects
   - Pull Requests: Enable "Allow squash merging"
3. **Branches**:
   - Default branch: `main`
   - Branch protection rules (optional):
     - Require pull request reviews
     - Require status checks to pass

### GitHub Actions

1. Go to Actions tab
2. Enable workflows
3. The `.github/workflows/build.yml` will run automatically on push

### Issues Templates

Create `.github/ISSUE_TEMPLATE/bug_report.md`:
```markdown
---
name: Bug report
about: Create a report to help us improve
title: '[BUG] '
labels: bug
assignees: ''
---

**Describe the bug**
A clear description of what the bug is.

**To Reproduce**
Steps to reproduce:
1. Build with '...'
2. Run with '...'
3. See error

**Expected behavior**
What you expected to happen.

**System Information:**
 - OS: [e.g. Ubuntu 22.04]
 - GCC Version: [e.g. 11.3.0]
 - QEMU Version: [e.g. 6.2.0]

**Additional context**
Any other context about the problem.
```

Create `.github/ISSUE_TEMPLATE/feature_request.md`:
```markdown
---
name: Feature request
about: Suggest an idea for this project
title: '[FEATURE] '
labels: enhancement
assignees: ''
---

**Is your feature request related to a problem?**
A clear description of the problem.

**Describe the solution you'd like**
What you want to happen.

**Describe alternatives you've considered**
Other solutions you've thought about.

**Additional context**
Any other context or screenshots.
```

## Step 5: Add Repository Badges

Add these to the top of README.md:

```markdown
![Build Status](https://github.com/chetanbhargavv/MinimalOS/workflows/Build%20and%20Test/badge.svg)
![License](https://img.shields.io/github/license/chetanbhargavv/MinimalOS)
![GitHub release](https://img.shields.io/github/v/release/chetanbhargavv/MinimalOS)
![GitHub stars](https://img.shields.io/github/stars/chetanbhargavv/MinimalOS)
```

## Step 6: Create First Release

1. Go to Releases → "Create a new release"
2. Click "Choose a tag" → Type `v1.0.0` → "Create new tag"
3. Release title: `MinimalOS v1.0.0 - Initial Release`
4. Description:
```markdown
## 🎉 Initial Release

First stable release of MinimalOS!

### Features
- ✅ Multiboot-compliant bootloader
- ✅ 32-bit protected mode kernel
- ✅ Memory management (4MB heap)
- ✅ Round-robin task scheduler
- ✅ VGA text mode driver (80x25, 16 colors)
- ✅ Interactive shell with commands
- ✅ Complete documentation

### Quick Start
```bash
git clone https://github.com/chetanbhargavv/MinimalOS.git
cd MinimalOS
make
make run
```

### System Requirements
- GCC with 32-bit support
- NASM assembler
- QEMU emulator
- GNU Make

See [INSTALL.md](INSTALL.md) for detailed instructions.

### Documentation
- [README.md](README.md) - Getting started
- [ARCHITECTURE.md](ARCHITECTURE.md) - Technical details
- [CONTRIBUTING.md](CONTRIBUTING.md) - How to contribute

### Known Issues
None at this time.

### Credits
Built with ❤️ for the OS development community.
```

5. Attach `kernel.bin` as a binary asset
6. Click "Publish release"

## Step 7: Enable GitHub Pages (Optional)

For documentation hosting:

1. Go to Settings → Pages
2. Source: Deploy from a branch
3. Branch: `main` / `docs` folder
4. Create `docs/index.html` with project documentation

## Step 8: Set Up Discussions

1. Go to Settings → Features
2. Enable Discussions
3. Create categories:
   - 💬 General
   - 💡 Ideas
   - 🙏 Q&A
   - 📣 Announcements
   - 🐛 Bug Reports

## Step 9: Add Social Preview

1. Go to Settings → General
2. Scroll to "Social preview"
3. Upload an image (1280x640px recommended)
   - Could be a screenshot of MinimalOS running
   - Or a custom banner with the logo

## Step 10: Update README with Your Info

Replace placeholders in README.md:
- `yourusername` → Your GitHub username
- `your.email@example.com` → Your email
- `[Your Name]` → Your name

## Recommended Repository Structure

```
MinimalOS/
├── .github/
│   ├── workflows/
│   │   └── build.yml
│   └── ISSUE_TEMPLATE/
│       ├── bug_report.md
│       └── feature_request.md
├── boot/
├── kernel/
├── include/
├── docs/ (optional)
├── .gitignore
├── ARCHITECTURE.md
├── CHANGELOG.md
├── CONTRIBUTING.md
├── CONTRIBUTORS.md
├── FAQ.md
├── INSTALL.md
├── LICENSE
├── Makefile
├── README.md
├── ROADMAP.md
├── SECURITY.md
└── screenshot.png
```

## Promoting Your Repository

### Add Topics

Go to repository → About → Topics:
- `operating-system`
- `kernel`
- `x86`
- `osdev`
- `c`
- `assembly`
- `nasm`
- `education`
- `multiboot`
- `qemu`
- `systems-programming`

### Share On

- Reddit: r/osdev, r/programming, r/C_Programming
- Hacker News
- Twitter/X with #osdev hashtag
- Dev.to
- LinkedIn

### Write a Blog Post

Consider writing about:
- Why you built MinimalOS
- What you learned
- Challenges you faced
- How others can learn from it

## Maintaining the Repository

### Regular Tasks

- [ ] Respond to issues within 48 hours
- [ ] Review pull requests weekly
- [ ] Update CHANGELOG.md for each release
- [ ] Keep dependencies updated
- [ ] Monitor GitHub Actions for failures
- [ ] Update documentation as needed

### Version Releases

Follow semantic versioning (MAJOR.MINOR.PATCH):
- MAJOR: Breaking changes
- MINOR: New features (backward compatible)
- PATCH: Bug fixes

## Getting Stars ⭐

Tips to get more stars:
1. **Quality documentation** - Make it easy to understand
2. **Active maintenance** - Respond to issues quickly
3. **Clear roadmap** - Show where the project is going
4. **Good first issues** - Label easy tasks for newcomers
5. **Engage community** - Be friendly and helpful
6. **Share progress** - Post updates regularly

## Support

Need help with GitHub setup?
- [GitHub Docs](https://docs.github.com/)
- [GitHub Community](https://github.community/)
- [Git Documentation](https://git-scm.com/doc)

---

**Ready to publish?** Follow these steps and your MinimalOS will be live on GitHub! 🚀
