#ifndef FUNCTION_7_LESSON_H_INCLUDED
#define FUNCTION_7_LESSON_H_INCLUDED

#include<stdio.h>

typedef char brace;

typedef struct Node{
    brace value;
    struct brace *next;
} node;

typedef struct{
    node *begin;
    size_t size;
} stack;

stack stack_create()
{
    stack new_stack = {NULL, 0};
    return new_stack;
}

void stack_push(stack *s, brace value)
{
    node *p = (node *)malloc(sizeof(node));
    p->value = value;
    p->next = s->begin;
    s->begin = p;
    s->size++;
}

brace stack_top(const stack *s)
{
    return s->begin->value;
}

brace stack_pop(stack *s)
{
    node *tmp = s->begin;
    brace tmp_value = tmp->value;
    s->begin = s->begin->next;
    s->size--;
    free(tmp);
    return tmp_value;
}

size_t stack_size(const stack *s)
{
    return s->size;
}

int stack_is_empty(const stack *s)
{
    return s->size == 0;
}

void stack_clear(stack *s)
{
    delete_list(s->begin);
    s->begin = NULL;
    s->size = 0;
}

void delete_list(node *p_begin)
{
    node *p = p_begin;
    while (p != NULL)
    {
        brace *tmp;
        tmp = p;
        p = p->next;
        free(tmp);
    }
}

int check_left_brace(char brace)
{
    return (brace == '(' || brace == '{'
            || brace == '[' || brace == '<');
}

int check_right_brace(char brace)
{
    return (brace == ')' || brace == '}'
            || brace == ']' || brace == '>');
}

char get_the_brace_left_pair(char brace)
{
    if (brace == ')') return '(';
    else if (brace == '}') return '{';
    else if (brace == ']') return '[';
    else if (brace == '>') return '<';
    else brace;
}

void braces_succession_checker()
{
    int good_braces_succession = 1;
    stack open_braces = stack_create();
    char brace = getchar();
    while (brace != '\n')
        {
            if (check_left_brace(brace))
            {
                stack_push(&open_braces, brace);
            }
            else if (check_right_brace(brace))
                {
                    if (stack_is_empty(&open_braces))
                        {
                            good_braces_succession = 0;
                            break;
                        }
                    char pair_candidate = stack_pop(&open_braces);
                    if (get_the_brace_left_pair(brace) != pair_candidate)
                        {
                            good_braces_succession = 0;
                            break;
                        }
                }
                brace = getchar();
        }
        if (good_braces_succession && !stack_is_empty(&open_braces))
            {
                good_braces_succession = 0;
            }
            if (good_braces_succession)
                {
                    printf("True\n");
                }
            else
                {
                    printf("False\n");
                }
}

void print_list(node *p_begin)
{
    node *p = p_begin;
    while (p != NULL)
        {
            printf("%c \t", p->value);
            p = p->next;
        }
}

void stack_print(const stack *s)
{
    print_list(s->begin);
}

#endif // FUNCTION_7_LESSON_H_INCLUDED
