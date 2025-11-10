#!/bin/bash
# Git setup script for MinimalOS

echo "🚀 Setting up MinimalOS Git repository..."
echo ""

# Initialize git if not already done
if [ ! -d .git ]; then
    echo "📦 Initializing Git repository..."
    git init
    echo "✅ Git initialized"
else
    echo "✅ Git already initialized"
fi

# Add all files
echo "📝 Adding files to Git..."
git add .

# Create initial commit
echo "💾 Creating initial commit..."
git commit -m "Initial commit: MinimalOS v1.0.0

- Multiboot bootloader with GRUB support
- 32-bit protected mode kernel
- Memory management with 4MB heap (kmalloc/kfree)
- Round-robin task scheduler (up to 8 tasks)
- VGA text mode driver (80x25, 16 colors)
- Interactive shell with commands (help, echo, clear)
- String utility library
- Comprehensive documentation (20+ files)
- MIT License
- CI/CD with GitHub Actions"

# Add remote
echo "🔗 Adding GitHub remote..."
git remote add origin https://github.com/chetanbhargavv/MinimalOS.git 2>/dev/null || echo "Remote already exists"

# Set main branch
echo "🌿 Setting main branch..."
git branch -M main

# Push to GitHub
echo "⬆️  Pushing to GitHub..."
echo ""
echo "Run this command to push:"
echo "  git push -u origin main"
echo ""
echo "Or if you've already pushed:"
echo "  git push"
echo ""
echo "✅ Git setup complete!"
echo ""
echo "📋 Next steps:"
echo "  1. Push to GitHub: git push -u origin main"
echo "  2. Take a screenshot of the OS running"
echo "  3. Create a release (v1.0.0) on GitHub"
echo "  4. Share your project!"
echo ""
echo "🎉 Your MinimalOS is ready for the world!"
