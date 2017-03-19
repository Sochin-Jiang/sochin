#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <glib.h>
#include <glib/gprintf.h>

/*
 * g_slist_append
 * g_slist_prepend
 * g_slist_reverse
 */
static void
test_slist_1(void)
{
    GSList *slist = NULL;
    GSList *st;
    gint nums[10] = {0,1,2,3,4,5,6,7,8,9};
    gint i;

    for (i = 0; i < 10; i++)
// GSList* g_slist_append(GSList *list, gpointer data);
        slist = g_slist_append(slist, &nums[i]);
    
    g_printf("The result should be: 0,1,2,3,4,5,6,7,8,9\n");
    g_printf("Begin:\n");
    for (i = 0; i < 10; i++) {
        st = g_slist_nth(slist, i);
        g_printf("%d,", *(gint*)st->data);
    }
    g_printf("\nDone\n");

// GSList* g_slist_reverse(GSList *list);
    slist = g_slist_reverse(slist);

    g_printf("The result should be: 9,8,7,6,5,4,3,2,1,0\n");
    g_printf("Begin:\n");
    for (i = 0; i < 10; i++) {
        st = g_slist_nth(slist, i);
        g_printf("%d,", *(gint*)st->data);
    }
    g_printf("\nDone\n");

    for (i = 0; i < 10; i++)
// GSList* g_slist_prepend(GSList *list, gpointer data);
        slist = g_slist_prepend(slist, &nums[i]);

    g_printf("The result should be: 9,8,7,6,5,4,3,2,1,0,9,8,7,6,5,4,3,2,1,0\n");
    g_printf("Begin:\n");
    for (i = 0; i < 20; i++) {
        st = g_slist_nth(slist, i);
        g_printf("%d,", *(gint*)st->data);
    }
    g_printf("\nDone\n");

    g_slist_free(slist);
}

/*
 * g_slist_insert_before
 * g_slist_insert
 * g_slist_nth
 * g_slist_copy
 */
static void
test_slist_2(void)
{
    GSList *slist = NULL;
    GSList *st;
    GSList *st2;
    gint nums[10] = {0,1,2,3,4,5,6,7,8,9};
    gint i;
// GSList* g_slist_insert_before(GSList *slist, GSList *sibling, gpointer data);
    slist = g_slist_insert_before(NULL, NULL, &nums[1]);

// GSList* g_slist_insert(GSList *list, gpointer data, gint position);
    slist = g_slist_insert(slist, &nums[3], 1);
    slist = g_slist_insert(slist, &nums[4], -1);
    slist = g_slist_insert(slist, &nums[0], 0);
    slist = g_slist_insert(slist, &nums[5], 100);
    slist = g_slist_insert_before(slist, NULL, &nums[6]);
    slist = g_slist_insert_before(slist, slist->next->next, &nums[2]);

    slist = g_slist_insert(slist, &nums[9], 7);
    slist = g_slist_insert(slist, &nums[8], 7);
    slist = g_slist_insert(slist, &nums[7], 7);

    g_printf("The result should be: 0,1,2,3,4,5,6,7,8,9\n");
    g_printf("Begin:\n");
    for (i = 0; i < 10; i++) {
// GSList* g_slist_nth(GSList *list, guint n);
        st = g_slist_nth(slist, i);
        g_printf("%d,", *(gint*)st->data);
    }
    g_printf("\nDone\n");

// GSList* g_slist_copy(GSList *list);
    st = g_slist_copy(slist);
    g_printf("The result should be: 0,1,2,3,4,5,6,7,8,9\n");
    g_printf("Begin:\n");
    for (i = 0; i < 10; i++) {
        st2 = g_slist_nth(st, i);
        g_printf("%d,", *(gint*)st2->data);
    }
    g_printf("\nDone\n");

    g_slist_free(st);
    g_slist_free(slist);
}

/*
 * g_slist_lenth
 * g_slist_remove
 * g_slist_remove_all
 * g_slist_last
 * g_slist_next
 */
static void
test_slist_3(void)
{
    GSList *slist = NULL;
    GSList *st;
    gint nums[10] = {0,1,2,3,4,5,6,7,8,9};
    gint i;

    for (i = 0; i < 10; i++) {
        slist = g_slist_append(slist, &nums[i]);
        slist = g_slist_append(slist, &nums[i]);
    }
// guint g_slist_lenth(GSList *list);
    g_printf("The length should be 20.\nResult:%d\n", g_slist_length(slist));

    for (i = 0; i < 10; i++)
// GSList* g_slist_remove_all(GSList *list, gconstpointer data);
        slist = g_slist_remove_all(slist, &nums[i]);
    g_printf("The length should be 0.\nResult:%d\n", g_slist_length(slist));

    for (i = 0; i < 10; i++) {
        slist = g_slist_append(slist, &nums[i]);
        slist = g_slist_append(slist, &nums[i]);
    }
    for (i = 0; i < 10; i++)
// GSList* g_slist_remove(GSList *list, gconstpointer data);
        slist = g_slist_remove(slist, &nums[i]);
    g_printf("The length should be 10.\nResult:%d\n", g_slist_length(slist));
    g_printf("The first should be 0.\nResult:%d\n", *(gint*)slist->data);
// GSList* g_slist_last(GSList *list);
    g_printf("The last should be 9.\nResult:%d\n", *(gint*)g_slist_last(slist)->data);

    g_printf("The first:");
    g_printf("%d\n", *(gint*)slist->data);    
    st = slist;
    for (i = 0; i < 9; i++) {
// #define g_slist_next (slist)
        st = g_slist_next(st);    
        g_printf("The next:%d\n", *(gint*)st->data);
    }

    g_slist_free(slist);
}

static gint
find_num(gconstpointer l, gconstpointer data)
{
    return *(gint*)l - GPOINTER_TO_INT(data);
}

/*
 * g_slist_index
 * g_slist_position
 * g_slist_find_custom
 */
static void
test_slist_4(void)
{
    GSList *slist = NULL;
    GSList *st;
    gint nums[10] = {0,1,2,3,4,5,6,7,8,9};
    gint i;

    for (i = 0; i < 10; i++) {
        slist = g_slist_append(slist, &nums[i]);
    }
// gint g_slist_index(GSList *list, gconstpointer data);
    g_printf("The index should be -1.\nResult:%d\n", g_slist_index(slist, NULL));
// gint g_slist_position(GSList *list, GSList *llink);
    g_printf("The position should be -1.\nResult:%d\n", g_slist_position(slist, NULL));

    for (i = 0; i < 10; i++) {
// GSList* g_slist_find_custom(GSList *list, gconstpointer data, GCompareFunc func);
        st = g_slist_find_custom(slist, GINT_TO_POINTER(i), find_num);
        g_printf("The position should be %d.\nResult:%d\n", i, g_slist_position(slist, st));
    }

    g_slist_free(slist);
}

#define SIZE        10
#define NUMBER_MAX    99

static guint32 array[SIZE];

static gint
sort(gconstpointer p1, gconstpointer p2)
{
    gint32 a, b;
    a = GPOINTER_TO_INT (p1);
    b = GPOINTER_TO_INT (p2);

    return (a > b ? +1 : a == b ? 0 : -1);
}

static gint
sort_r(gconstpointer p1, gconstpointer p2)
{
    gint32 a, b;
    a = GPOINTER_TO_INT (p1);
    b = GPOINTER_TO_INT (p2);

    return (a < b ? +1 : a == b ? 0 : -1);
}

/*
 * g_slist_sort
 * g_slist_sort_with_data
 * g_slist_nth_data
 */
static void
test_slist_5(void)
{
    GSList *slist = NULL;
    gint i;

    for (i = 0; i < SIZE; i++)
        slist = g_slist_append(slist, GINT_TO_POINTER(array[i]));

// GSList* g_slist_sort(GSList *list, GCompareFunc compare);
    slist = g_slist_sort(slist, sort);

    g_printf("The result should be sorted.\nResult:");
    for (i = 0; i < SIZE; i++) {
// gpointer g_slist_nth_data(GSList *list, guint n);
        gpointer p = g_slist_nth_data(slist, i);
        g_printf("%d,", GPOINTER_TO_INT(p));
    }
    g_printf("\n");

// GSList* g_slist_sort_with_data(GSList *list, GCompareDataFunc compare_func, gpinter user_data);
    slist = g_slist_sort_with_data(slist, (GCompareDataFunc)sort_r, NULL);
    g_printf("The result should be sorted[reversed].\nResult:");
    for (i = 0; i < SIZE; i++) {
        gpointer p = g_slist_nth_data(slist, i);
        g_printf("%d,", GPOINTER_TO_INT(p));
    }
    g_printf("\n");

    g_slist_free(slist);
}

static void
print(gpointer p1, gpointer p2)
{
    g_printf("%d,", GPOINTER_TO_INT(p1));
}

/*
 * g_slist_insert_sorted
 * g_slist_insert_sorted_with_data
 * g_slist_concat
 * g_slist_foreach
 */
static void
test_slist_6(void)
{
    GSList *slist = NULL;
    GSList *st = NULL;
    GSList *sc = NULL;
    gint i;

    for (i = 0; i < SIZE; i++) {
// GSList* g_slist_insert_sorted(GSList *list, gpointer data, GCompareFunc func);
        slist = g_slist_insert_sorted(slist, GINT_TO_POINTER(array[i]), sort);
// GSList* g_slist_insert_sorted_with_data(GSList *list, gpointer data, 
//                            GCompareDataFunc func,
//                            gpinter user_data);
        st = g_slist_insert_sorted_with_data(st, GINT_TO_POINTER(array[i]), 
                            (GCompareDataFunc)sort_r,
                            NULL);
    }
    
    g_printf("The result should be sorted.\nResult:");
    for (i = 0; i < SIZE; i++) {
        gpointer p = g_slist_nth_data(slist, i);
        g_printf("%d,", GPOINTER_TO_INT(p));
    }
    g_printf("\n");

    g_printf("The result should be sorted[reversed].\nResult:");
    for (i = 0; i < SIZE; i++) {
        gpointer p = g_slist_nth_data(st, i);
        g_printf("%d,", GPOINTER_TO_INT(p));
    }
    g_printf("\n");

// GSList* g_slist_concat(GSList *list1, *list2);
    sc = g_slist_concat(slist, st);

    g_printf("The result should be concated.\nResult:");
// void g_slist_foreach(GSList *list, GFunc func, gpointer user_data);
    g_slist_foreach(sc, (GFunc)print, NULL);
    g_printf("\n");
    
    g_slist_free(slist);
    g_slist_free(st);

}

int
main(void)
{
    printf("BEGIN:\n************************************************************\n");
    printf("\n------------------------------------------------------------\ntest_slist_1:\n");
    printf("------------------------------------------------------------\n");
    test_slist_1();
    printf("\n------------------------------------------------------------\ntest_slist_2:\n");
    printf("------------------------------------------------------------\n");
    test_slist_2();
    printf("\n------------------------------------------------------------\ntest_slist_3:\n");
    printf("------------------------------------------------------------\n");
    test_slist_3();
    printf("\n------------------------------------------------------------\ntest_slist_4:\n");
    printf("------------------------------------------------------------\n");
    test_slist_4();

    int i;
    srand((unsigned)time(0));
    printf("The init array is:\n");
    for (i = 0; i < SIZE; i++) {
        array[i] = rand() % (NUMBER_MAX+1);
        printf("%d,", array[i]);
    }
    printf("\n");

    printf("\n------------------------------------------------------------\ntest_slist_5:\n");
    printf("------------------------------------------------------------\n");
    test_slist_5();

    printf("\n------------------------------------------------------------\ntest_slist_6:\n");
    printf("------------------------------------------------------------\n");
    test_slist_6();

    printf("\n************************************************************\nDONE\n");

    return 0;
}