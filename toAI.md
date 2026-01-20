# AI Development Guidelines

This document provides essential guidelines for AI assistants working on the PyInCpp project.

## Branch Management

### Branch Strategy
- **main branch**: Used for stable releases only. No direct development should occur on this branch.
- **develop branch**: Used for developing new features and improvements.

### Release Workflow
When creating a new release:
1. Merge `develop` into `main` (never make direct changes to `main`)
2. The new version number MUST be different from the previous `main` version
3. Create a version tag (e.g., `v1.1`, `v1.2`) on the merged commit
4. Push both the branch and the tag to remote

### Feature Development
- All new features must be developed on the `develop` branch
- When adding new features to `develop`, update the README's "Version History" section
- Use a version number higher than the current `main` version (e.g., if `main` is v1.0, use v1.1 or v1.2)
- Do NOT include dates in the version history entries

## Testing Requirements

### Pre-Merge Testing
Before merging `develop` into `main`:
1. Run the complete test suite: `cd test && ./runTest.bat`
2. ALL tests must pass (12/12 tests)
3. No test failures are acceptable

### Test Execution
```bash
cd test
./runTest.bat
```

Expected output:
```
========================================
Test Summary
========================================
Passed: 12
Failed: 0
Total:  12
========================================
```

## Code Standards

### C++ Version
- **Maximum C++ version**: C++17
- Do NOT use C++20 or newer features
- This ensures broad compatibility

### Code Style
- Keep code concise and simple
- Prioritize readability over clever optimizations
- Follow existing code patterns and conventions

### Documentation Style
- Use **Doxygen-style** comments for all public APIs and complex logic
- Comments should be in English
- Example:
```cpp
/**
 * @brief Checks if the value is in the container
 * @param proxy The proxy object containing the value to check
 * @param container The container to search in
 * @return true if the value is found, false otherwise
 */
bool operator>(InProxy<ValType> proxy, const Container& container);
```

## Version History Format

### Main Branch (Released Versions)
```markdown
### v1.0 (2026-01-20)
- Feature description
- Another feature
```

### Develop Branch (Unreleased Features)
```markdown
### v1.1 (Unreleased)
- New feature being developed
- Another new feature
```

## Important Rules

1. **Never** commit directly to `main` branch
2. **Always** run tests before merging to `main`
3. **Always** ensure version numbers are incremented
4. **Always** use Doxygen-style comments
5. **Never** use C++20+ features
6. **Always** update README when adding features to `develop`

## Quick Reference

| Action | Command |
|--------|---------|
| Run tests | `cd test && ./runTest.bat` |
| Switch to develop | `git checkout develop` |
| Merge develop to main | `git checkout main && git merge develop` |
| Create version tag | `git tag -a v1.1 -m "Release message"` |
| Push tag | `git push origin v1.1` |

## Project Structure

```
PyInCpp/
├── source/
│   └── PyInCpp.hpp          # Main library header
├── test/
│   ├── test.cpp             # Test suite
│   ├── CMakeLists.txt       # CMake configuration
│   ├── runTest.bat          # Test runner script
│   └── BUILD.md             # Build instructions
├── README.md                # Project documentation
├── .gitignore               # Git ignore rules
└── toAI.md                  # This file
```

## Contact

For questions or clarifications, refer to the project README or create an issue on GitHub.
