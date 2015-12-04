#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>

GtkWidget* MainWindow_init(GtkWidget *Window)
{
  Window = gtk_window_new(GTK_WINDOW_TOPLEVEL); // create a new window
  g_signal_connect(G_OBJECT(Window), "delete-event", G_CALLBACK(gtk_main_quit), NULL);
  gtk_window_set_title(GTK_WINDOW(Window), "Facial recognation\tby\tThe Suicide Squad"); // set the title
  gint width = 50; // test
  gint height = 50; // test 
  gtk_window_set_default_size(GTK_WINDOW(Window), width, height); // set size 
  gtk_window_set_position(GTK_WINDOW(Window),GTK_WIN_POS_CENTER); // set the window at the center of the screen
  gtk_window_set_deletable (GTK_WINDOW(Window),TRUE);//enable close button
  gtk_widget_show(Window);//display the window
  gtk_main();
  return Window;
}

int main(int argc, char **argv)
{
  GtkWidget *MainWindow = NULL;
  gtk_init(&argc, &argv);
  MainWindow = MainWindow_init(MainWindow); //Init The Main Windows of Interface with A title. The window is center in the middle of the screen.
  return EXIT_SUCCESS;
}
