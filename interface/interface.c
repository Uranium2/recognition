#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>
//Fction CALLBACK
void cb_quit(GtkWidget *Window)
{
  gtk_main_quit();
}
//FIN Fction CALLBACK

//FCTION 
GtkWidget* MainWindow_init(GtkWidget *Window)
{
  Window = gtk_window_new(GTK_WINDOW_TOPLEVEL); // create a new window
  gtk_window_set_title(GTK_WINDOW(Window), "Facial recognation\tby\tThe Suicide Squad"); // set the title
  gint width = 800; // test
  gint height = 800; // test 
  gtk_window_set_default_size(GTK_WINDOW(Window), width, height); // set size 
  gtk_window_set_position(GTK_WINDOW(Window),GTK_WIN_POS_CENTER); // set the window at the center of the screen
  gtk_window_set_deletable (GTK_WINDOW(Window),TRUE);//enable close button
  // gtk_window_set_resizable(GTK_WINDOW(Window), FALSE); //disable resize by the user
  return Window;
}

GtkWidget* initbutton(GtkWidget *button,const gchar *str)
{
  button = gtk_button_new_with_label(str);//Init button with label str
  return button;
}
//FIN FCtion



//////////////MAIN///////////////
int main(int argc, char **argv)
{ 
  //declaration gtkwidget
  GtkWidget *MainWindow = NULL;   // MainWindow
  GtkWidget *test = NULL;
  GtkWidget *Align_button1 = NULL;
  //fin declaration widget

  //init
  gtk_init(&argc, &argv);
  MainWindow = MainWindow_init(MainWindow); //Init The Main Windows of Interface with A title. The window is center in the middle of the screen.
  Align_button1 = gtk_alignment_new( 0,0.5,0.5,0.5 );//set alignement 1 in MainWindows
  test = initbutton(test,"test");//init button test
  //fin init
  
  //prgm
  gtk_container_add(GTK_CONTAINER(Align_button1),test);
  gtk_container_add(GTK_CONTAINER(MainWindow),Align_button1);
  gtk_widget_show_all(MainWindow);
  //fin prgm  

  //signal
  gtk_signal_connect (GTK_OBJECT (test), "clicked",GTK_SIGNAL_FUNC (cb_quit), NULL);     // Appelle la function lorsque l'on clique surle bouton test
  gtk_widget_show_all(MainWindow);
  g_signal_connect(G_OBJECT(MainWindow), "destroy", G_CALLBACK(cb_quit), NULL);
  gtk_main();
  return EXIT_SUCCESS;
}
