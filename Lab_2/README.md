## Structs in C++

You decide to create a program that allows the user to enter information about a student, such as name, student ID, and grade. You want to store this information in a structured way so that it can be easily accessed and changed.

To achieve this, you must create a "struct" named "Student" containing the following fields.

```bash
  name: a string that stores the student's name
  id: an integer that stores the student's ID number
  note: a float that stores the student's grade
```
Next, you must create an array of type "Student" to store information for multiple students. (The size of the array is determined by user input.)
Your program prompts the user to enter the student's name, ID, and grade, and stores this information in an instance of the "Student" structure. It then adds this instance to the student array.

After collecting all the information of the students, the program:

```bash
  * search for a specific student by ID on the user's data,
  * sort students by grade
  * allows all students to perform various operations such as calculating the average grade.
```
