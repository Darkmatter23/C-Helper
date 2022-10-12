# C++ Helper

## Format
Beautify code and print number of input code's lines and maximum number of lines of functions
Beautifying is converting 8 spaces to one tab character. also convert any multi-line comments to multiple one-line comments.

**Example:** ```C:\> helper.exe format hello_world.cpp```

## Replace
Replace first word with the second word in all of the code

**Example:** ```C:\> helper.exe replace test_file.cpp -r int, long -r float, double -r std::endl, '\n'```

## Create by template
Create a prepared template to start a project.

**Example:** ```C:\> helper.exe create-by-template sample_program.cpp```

```c++
#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef vector<int> ints
typedef vector<string> strings

int main() {
    return 0;
}
```
