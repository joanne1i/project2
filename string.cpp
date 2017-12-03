xx11::string&, std::__cxx11::string&)’
  if (Expression().isEqual(infix1, infix2))
                                         ^
In file included from string.h:2:0,
                 from string.cpp:2:
expression.h:26:7: note: candidate: bool Expression::isEqual(std::__cxx11::string)
  bool isEqual(string exp);
       ^~~~~~~
expression.h:26:7: note:   candidate expects 1 argument, 2 provided
expression.cpp:77:6: error: prototype for ‘bool Expression::isEqual(std::__cxx11::string, std::__cxx11::string)’ does not match any in class ‘Expression’
 bool Expression::isEqual(string infix1, string infix2)
      ^~~~~~~~~~
In file included from expression.cpp:3:0:
expression.h:26:7: error: candidate is: bool Expression::isEqual(std::__cxx11::string)
  bool isEqual(string exp);
       ^~~~~~~
[jennyzhang@csil project2]$ g++ -o string string.cpp expression.cpp list.cpp node.cpp
[jennyzhang@csil project2]$ ./string
Please enter 1 for Expression Evaluation, 2 for Expression Comparison, or 3 to exit the program
1
[jennyzhang@csil project2]$ ./string
Please enter 1 for Expression Evaluation, 2 for Expression Comparison, or 3 to exit the program
1
[jennyzhang@csil project2]$ g++ -o string string.cpp expression.cpp list.cpp node.cpp
[jennyzhang@csil project2]$ ./string
Please enter 1 for Expression Evaluation, 2 for Expression Comparison, or 3 to exit the program
1
Enter infix: 
Segmentation fault (core dumped)
[jennyzhang@csil project2]$ emacs expression.cpp
[jennyzhang@csil project2]$ g++ -o string string.cpp expression.cpp list.cpp node.cpp
[jennyzhang@csil project2]$ ./string
Please enter 1 for Expression Evaluation, 2 for Expression Comparison, or 3 to exit the program
1
Enter infix: 
Segmentation fault (core dumped)
[jennyzhang@csil project2]$ emacs expression.h
[jennyzhang@csil project2]$ g++ -o string string.cpp expression.cpp list.cpp node.cpp
/tmp/cc9DpRGx.o: In function `Expression::eval(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >)':
expression.cpp:(.text+0x374): undefined reference to `Expression::balanced(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >)'
collect2: error: ld returned 1 exit status
[jennyzhang@csil project2]$ clear

[jennyzhang@csil project2]$ g++ -o string string.cpp expression.cpp list.cpp node.cpp
/tmp/ccHSF5Id.o: In function `Expression::eval(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >)':
expression.cpp:(.text+0x374): undefined reference to `Expression::balanced(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >)'
collect2: error: ld returned 1 exit status
[jennyzhang@csil project2]$ emacs expression.cpp
[jennyzhang@csil project2]$ emacs string.cpp
[jennyzhang@csil project2]$ gdb string
GNU gdb (GDB) Fedora 7.12.1-48.fc25
Copyright (C) 2017 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "x86_64-redhat-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
<http://www.gnu.org/software/gdb/documentation/>.
For help, type "help".
Type "apropos word" to search for commands related to "word"...
string: No such file or directory.
(gdb) run
Starting program:  
No executable file specified.
Use the "file" or "exec-file" command.
(gdb) quit
[jennyzhang@csil project2]$ gdb string
GNU gdb (GDB) Fedora 7.12.1-48.fc25
Copyright (C) 2017 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "x86_64-redhat-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
<http://www.gnu.org/software/gdb/documentation/>.
For help, type "help".
Type "apropos word" to search for commands related to "word"...
string: No such file or directory.
(gdb) run
Starting program:  
No executable file specified.
Use the "file" or "exec-file" command.
(gdb) quit
[jennyzhang@csil project2]$ emacs string.cpp
[jennyzhang@csil project2]$ emacs string.cpp

File Edit Options Buffers Tools C++ Help                                               
    cin >> input;
    switch(input)
      {
      case 1:
        cout << "Enter infix: \n";
        getline(cin, infix);
        cout << "Result: " << Expression().eval(infix) << endl;
        break;
      case 2:
        cout << "Enter infix 1: \n";
        getline(cin, infix1);
        cout << "Enter infix 2: \n";
        getline(cin, infix2);
        if (Expression().isEqual(infix1, infix2))
          {
            cout << infix1 << " is equal to " << infix2;
          }
        else
          {
            cout << infix1 << " is not equal to " << infix2;
          }
        break;
      case 3:
        cout << "Goodbye!" << endl;
        return 0;
      }


}
