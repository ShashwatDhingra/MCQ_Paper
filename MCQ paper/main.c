// Multi Choice Question Paper.

#include <stdio.h>
#include <stdlib.h>
struct mcq_paper // Structure to store name and Roll Number.
{
    char name[20];
    int roll_no;
    char answer[10];
    int marks;
    int flag[10];
};

int op1();
int op2();
/* Different funcitons for each Question*/
int Ques1();
int Ques2();
int Ques3();
int Ques4();
int Ques5();
int Ques6();
int Ques7();
int Ques8();
int Ques9();
int Ques10();

int main()
{
    int op;

    printf("\n\n\n\t\t\t\t\t\t =======================\n");
    printf("\t\t\t\t\t\t| M C Q   P R O J E C T |\n");
    printf("\t\t\t\t\t\t =======================\n\n\n");

    /* Options for Attempt papaer and print Paper*/

    printf(" 1. Attempt MCQ Paper.\n");
    printf(" 2. Print Result Sheet.\n\n");
    printf("Select: ");

    scanf("%d", &op);

    switch (op)
    {
    case (1):
    {
        op1();
    }
    break;

    case (2):
    {
        op2();
    }
    break;

    default:
    {
        printf("Enter correct Option!");
    }
    break;
    }

    return (0);
}

/* Function for Attempting the MCQ Paper*/
int op1()
{
    char roll_no[4];

    struct mcq_paper student;

    FILE *fp; // File pointer to connect it with File.

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

    printf("\t\t\t\t\t     =========================\n");
    printf("\t\t\t\t\t    | C Programming MCQ Paper |\n");
    printf("\t\t\t\t\t     =========================\n");

    printf("Total Time: 30 Min\t\t\t\t\t\t\t\t             Total marks : 20 Marks\n\n");

    printf("Note: All questions are compulsory to Attempt.\n");
    printf("----------------------------------------------\n\n");

    printf(" Instructions:\n 1. Write Capital Alphabet of Correct Option.\n 2. Each question  is of 2 marks\n\n");

    fflush(stdin);
    printf("Name: ");
    scanf("%s", student.name);

    fflush(stdin);
    printf("\t\t\t\t\t\t\t\t\t\t\t\tRoll No.: ");
    scanf("%s", roll_no);

    student.roll_no = atoi(roll_no);

    /* Opening File to Store data. */
    fp = fopen(roll_no, "w");

    fflush(stdin);
    student.answer[0] = Ques1();
    printf("\n");
    fflush(stdin);
    student.answer[1] = Ques2();
    printf("\n");
    fflush(stdin);
    student.answer[2] = Ques3();
    printf("\n");
    fflush(stdin);
    student.answer[3] = Ques4();
    printf("\n");
    fflush(stdin);
    student.answer[4] = Ques5();
    printf("\n");
    fflush(stdin);
    student.answer[5] = Ques6();
    printf("\n");
    fflush(stdin);
    student.answer[6] = Ques7();
    printf("\n");
    fflush(stdin);
    student.answer[7] = Ques8();
    printf("\n");
    fflush(stdin);
    student.answer[8] = Ques9();
    printf("\n");
    fflush(stdin);
    student.answer[9] = Ques10();
    printf("\n");
    fflush(stdin);

    student.marks = 0;

    /* answer[0][2][4][6][8]*/
    for (int i = 0; i < 10; i += 2)
    {
        if (student.answer[i] == 'a')
        {
            student.marks += 2;
            student.flag[i] = 1;
        }

        else
        {
            student.flag[i] = 0;
        }
    }

    /* answer[1][3][5][7][9]*/
    for (int i = 1; i < 10; i += 2)
    {
        if (student.answer[i] == 'c')
        {
            student.marks += 2;
            student.flag[i] = 1;
        }

        else
        {
            student.flag[i] = 0;
        }
    }

    /* Storing the Answer in Different File. */

    fwrite(&student, sizeof(struct mcq_paper), 1, fp);

    fclose(fp);

    printf("Answers Submitted Successfully!");

    printf("\n\nPress any Key to End.");
    system("pause>nul");
}

/* Function for Printing the Result Sheet of Particular Student*/
int op2()
{
    struct mcq_paper student;
    char roll_no[4];

    FILE *fp;

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("Enter the Roll Number of Student: ");
    scanf("%s", &roll_no);
    printf("\n\n\n\n");

    fp = fopen(roll_no, "r");

    if (fp == NULL)
    {
        printf("No File is Available of this Roll Number.");

        printf("\nPress any Key to End.");
        system("pause>nul");
        return (0);
    }

    /* Importing the File content in student Structure. */

    fread(&student, sizeof(struct mcq_paper), 1, fp);

    printf("\t\t\t\t\t    || C Programming MCQ Paper Result ||\n\n\n");

    printf("Name -> ");
    puts(student.name);
    printf("\n");

    printf("Roll No. -> ");
    puts(roll_no);
    printf("\n\n");

    printf("Marks Got -> %d\n\n", student.marks);

    if (student.marks < 8)
    {
        printf("Result -> Fail :/\n\n");
    }

    else
    {
        printf("Result -> Pass :)\n\n");
    }

    if (student.flag[0] == 0)
    {
        printf("Wrong Attempted Question : \n");
        printf("Q1. Who is the father of C language?\n\n");
        printf("a) Dennis Ritchie\nb) James Gosling\nc) Steve Jobs\nd) Rasmus Lerdor\n\n");
        printf("Correct answer: (a)\n");
        printf("Explanation --> Nothing :)\n\n");
    }

    if (student.flag[1] == 0)
    {
        printf("Wrong Attempted Question : \n");
        printf("Q 2. How is an array initialized in C language?\n\n");
        printf("a) int a[] = new int[3]\nb) int a = {1, 2, 3}\nc) int a[3] = {1, 2, 3}\nd) int a(3) = [1, 2, 3]\n\n");
        printf("Correct answer: (c)\n");
        printf("Explanation --> Nothing :)\n\n");
    }
    if (student.flag[2] == 0)
    {
        printf("Wrong Attempted Question : \n");
        printf("Q 3. Which of the following is not a valid C variable name?\n");
        printf("a) int $main\nb) float rate \nc) int variable_count \nd)int number\n\n");
        printf("Correct answer: (a)\n");
        printf("Explanation --> Nothing :)\n\n");
    }

    if (student.flag[3] == 0)
    {
        printf("Wrong Attempted Question : \n");
        printf("Q4. All keywords in C are in ____________\n");
        printf("a) CamelCase letters\nb) UpperCase letters\nc) LowerCase letters\nd) None of the mentioned\n\n");
        printf("Correct answer: (c)\n");
        printf("Explanation --> Nothing :)\n\n");
    }

    if (student.flag[4] == 0)
    {
        printf("Wrong Attempted Question : \n");
        printf("Q 5. Which is valid C expression?\n");
        printf("a) int my_num = 100000\nb) int my_num = 100,000\nc) int my num = 1000 \nd) int $my_num = 10000\n\n");
        printf("Correct answer: (a)\n");
        printf("Explanation --> Nothing :)\n\n");
    }

    if (student.flag[5] == 0)
    {
        printf("Wrong Attempted Question : \n");
        printf("Q 6. Which of the following cannot be a variable name in C?\n\n");
        printf("a) friend \nb) true\nc) volatile\nd) export\n");
        printf("Correct answer: (c)\n");
        printf("Explanation --> Nothing :)\n\n");
    }

    if (student.flag[6] == 0)
    {
        printf("Wrong Attempted Question : \n");
        printf("Q 7. How many number of pointer (*) does C have against a pointer variable declaration?\n\n");
        printf("a) No limits\nb) 127\nc) 255\nd) 7\n");
        printf("Correct answer: (a)\n");
        printf("Explanation --> Nothing :)\n\n");
    }

    if (student.flag[7] == 0)
    {
        printf("Wrong Attempted Question : \n");
        printf("Q 8. Which of the following is not possible statically in C language?\n");
        printf("a) Cuboidal Array\nb) Rectangular Array\nc) Jagged Array\nd) Multidimensional Array\n\n");
        printf("Correct answer: (c)\n");
        printf("Explanation --> Nothing :)\n\n");
    }

    if (student.flag[8] == 0)
    {
        printf("Wrong Attempted Question : \n");
        printf("Q 9. In C language, FILE is of which data type?\n");
        printf("a) struct\nb) char \nc) int\nd) None of the mentioned\n\n");
        printf("Correct answer: (a)\n");
        printf("Explanation --> Nothing :)\n\n");
    }

    if (student.flag[9] == 0)
    {
        printf("Wrong Attempted Question : \n");
        printf("Q 10. What is the sizeof(char) in a 64-bit C compiler?\n\n");
        printf("a) 1 bit\nb) 2 bits\nc) 1 Byte\nd) 2 Bytes\n");
        printf("Correct answer: (c)\n");
        printf("Explanation --> Nothing :)\n\n");
    }

    /* If not a Single a Question is Wromg */
    if ((student.flag[0] && student.flag[1] && student.flag[2] && student.flag[3] && student.flag[4] && student.flag[5] && student.flag[6] && student.flag[7] && student.flag[8] && student.flag[9]) == 1)
    {
        printf("\n\nGreat! Not a Single Question is Wrong\n\n");
    }

    if (student.marks <= 10)
    {
        printf("Good!\n");
    }

    else if (student.marks <= 15)
    {
        printf("Great!\n");
    }

    else if (student.marks <= 20)
    {
        printf("Excellent!\n");
    }

    printf("\nPress any Key to End.");
    system("pause>nul");
}
// answer[0]
int Ques1()
{
    char answer;

    printf("Q1. Who is the father of C language?\n\n");
    printf("a) Dennis Ritchie\nb) James Gosling\nc) Steve Jobs\nd) Rasmus Lerdor\n\n");
    printf("Answer: ");
    scanf("%c", &answer);

    return (answer);
}
// answer[1]
int Ques2()
{
    char answer;

    printf("Q 2. How is an array initialized in C language?\n\n");
    printf("a) int a[] = new int[3]\nb) int a = {1, 2, 3}\nc) int a[3] = {1, 2, 3}\nd) int a(3) = [1, 2, 3]\n\n");
    printf("Answer: ");
    scanf("%c", &answer);

    return (answer);
}
// answer[2]
int Ques3()
{
    char answer;
    printf("Q 3. Which of the following is not a valid C variable name?\n");
    printf("a) int $main\nb) float rate \nc) int variable_count \nd)int number\n\n");
    printf("Answer: ");
    scanf("%c", &answer);

    return (answer);
}
// answer[3]
int Ques4()
{
    char answer;

    printf("Q4. All keywords in C are in ____________\n");
    printf("a) CamelCase letters\nb) UpperCase letters\nc) LowerCase letters\nd) None of the mentioned\n\n");
    printf("Answer: ");
    scanf("%c", &answer);

    return (answer);
}
// answer[4]
int Ques5()
{
    char answer;

    printf("Q 5. Which is valid C expression?\n");
    printf("a) int my_num = 100000\nb) int my_num = 100,000\nc) int my num = 1000 \nd) int $my_num = 10000\n\n");
    printf("Answer: ");
    scanf("%c", &answer);

    return (answer);
}
// answer[5]
int Ques6()
{
    char answer;

    printf("Q 6. Which of the following cannot be a variable name in C?\n\n");
    printf("a) friend \nb) true\nc) volatile\nd) export\n");
    printf("Answer: ");
    scanf("%c", &answer);

    return (answer);
}
// answer[6]
int Ques7()
{
    char answer;

    printf("Q 7. How many number of pointer (*) does C have against a pointer variable declaration?\n\n");
    printf("a) No limits\nb) 127\nc) 255\nd) 7\n");
    printf("Answer: ");
    scanf("%c", &answer);

    return (answer);
}
// answer[7]
int Ques8()
{
    char answer;

    printf("Q 8. Which of the following is not possible statically in C language?\n");
    printf("a) Cuboidal Array\nb) Rectangular Array\nc) Jagged Array\nd) Multidimensional Array\n\n");
    printf("Answer: ");
    scanf("%c", &answer);

    return (answer);
}
// answer[8]
int Ques9()
{
    char answer;

    printf("Q 9. In C language, FILE is of which data type?\n");
    printf("a) struct\nb) char \nc) int\nd) None of the mentioned\n\n");
    printf("Answer: ");
    scanf("%c", &answer);

    return (answer);
}
// answer[9]
int Ques10()
{
    char answer;

    printf("Q 10. What is the sizeof(char) in a 64-bit C compiler?\n\n");
    printf("a) 1 bit\nb) 2 bits\nc) 1 Byte\nd) 2 Bytes\n");
    printf("Answer: ");
    scanf("%c", &answer);

    return (answer);
}
