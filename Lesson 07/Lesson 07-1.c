#include <stdio.h>
#include <stdlib.h>
int check_left_brace(char brace);
int check_right_brace(char brace);
char get_the_brace_left_pair(char brace);
void braces_succession_checker();
typedef char tData;
typedef struct sNode{
    tData value;
    struct sNode *next;
} tNode;

typedef struct{
    tNode *p_begin;
    size_t m_size;
} tStack;

void stack_push(tStack *s, tData value);
tData stack_pop(tStack *s);
tData stack_top(const tStack *s);
size_t stack_size(const tStack *s);
void stack_clear(tStack *s);
tStack stack_create();
void stack_print(const tStack *s);
int stack_is_empty(const tStack *s);

tData stack_pop(tStack *s)
{
    tNode *tmp = s->p_begin;
    tData tmp_value = tmp->value;
    s->p_begin = s->p_begin->next;
    s->m_size--;
    free(tmp);
    return tmp_value;
}

tData stack_top(const tStack *s)
{
    return s->p_begin->value;
}

tStack stack_create()
{
    tStack new_stack = {NULL, 0};
    return new_stack;
}

void print_list(tNode *p_begin)
{
    tNode *p = p_begin;
    while (p != NULL) {
        //����������� ��������� ������
        printf("%c \t", p->value);
        //������� ������ !!!
        p = p->next;
    }
}

void delete_list(tNode *p_begin)
{
    tNode *p = p_begin;
    while (p != NULL) {
        tNode *tmp;
        tmp = p;
        //������� ������ !!!
        p = p->next;
        //������� ������ ������
        free(tmp);
    }
}

void stack_push(tStack *s, tData value)
{
    tNode *p = (tNode *)malloc(sizeof(tNode));
    p->value = value;
    p->next = s->p_begin;
    s->p_begin = p;
    s->m_size++;
}

size_t stack_size(const tStack *s)
{
    return s->m_size;
}

void stack_clear(tStack *s)
{
    delete_list(s->p_begin);
    s->p_begin = NULL;
    s->m_size = 0;
}

void stack_print(const tStack *s)
{
    print_list(s->p_begin);
}

int stack_is_empty(const tStack *s)
{
    return s->m_size == 0;
}

int main()
{
    braces_succession_checker();
    return 0;
}
void braces_succession_checker()
{
    int good_braces_succession = 1;
    tStack open_braces = stack_create();
    char brace = getchar();
    while (brace != '\n') {
        if (check_left_brace(brace)) {
            stack_push(&open_braces, brace);
        } else if (check_right_brace(brace)) {
            if (stack_is_empty(&open_braces)) {
                good_braces_succession = 0;
                break;
            }
            char pair_candidate = stack_pop(&open_braces);
            if (get_the_brace_left_pair(brace) != pair_candidate) {
                good_braces_succession = 0;
                break;
            }
        } //else ������ ������ �� ������
        brace = getchar();
    }
    if (good_braces_succession
        && !stack_is_empty(&open_braces)) {
        //�������� ���������� ����� ������
        good_braces_succession = 0;
    }
    if (good_braces_succession) {
        printf("OK!\n");
    } else {
        printf("Bad succession!\n");
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
