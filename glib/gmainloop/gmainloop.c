#include<glib.h> 
GMainLoop* loop;
int main(int argc, char* argv[])
{
    //g_thread_init�Ǳ���ģ�GMainLoop��Ҫgthread���֧�֡�
    if(g_thread_supported() == 0)
        g_thread_init(NULL);
    //����һ��ѭ���壬�Ȳ��ܲ�������˼��
    g_print("g_main_loop_new\n");
    loop = g_main_loop_new(NULL, FALSE);
    //�����ѭ����������
    g_print("g_main_loop_run\n");
    g_main_loop_run(loop);
    //ѭ��������ɺ󣬼�������һ
    //glib�ĺܶ�ṹ���ͺ�c++������ָ�����ƣ�ӵ��һ��������
    //��������Ϊ0ʱ���Զ��ͷ���Դ��
    g_print("g_main_loop_unref\n");
    g_main_loop_unref(loop);
    return 0;
}