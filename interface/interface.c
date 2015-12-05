#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>
//Fction CALLBACK
void cb_quit(GtkWidget *Window)
{
  gtk_main_quit();
  (void)Window;
}
void cb_picture(GtkWidget *Window)   //open a window to repertory
{
  (void)Window;
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
  return Window;
}

GtkWidget* initbutton(GtkWidget *button,const gchar *str)
{
  button = gtk_button_new_with_label(str);//Init button with label str
  return button;
}
//FIN 











/*MAIN*/
int main(int argc, char **argv)
{ 
  //declaration gtkwidget
  GtkWidget *GtkHbox = NULL; //Box horizontal de la Mainwindow
  GtkWidget *GtkVbox = NULL; // Box vertical de la box horizontal 2/2
  GtkWidget *MainWindow = NULL;  
  GtkWidget *Menubar = NULL; // appartient a la horizontal box 1/2
  GtkWidget *button1 = NULL; // appartient a la vertical box1/2 de la horizontal box 2/2
  //GtkWidget *Align_button1 = NULL;
  GtkWidget *Align_button2 = NULL;
  //fin declaration widget
  





  /*ALIGNEMENT SCALE MUST BE xscale = 0.1 , yscale = 0.05*/

  //init
  gtk_init(&argc, &argv);//init GTK
  //  GtkVbox = gtk_vbox_new(TRUE,0);
  GtkHbox = gtk_hbox_new(FALSE,0);
  MainWindow = MainWindow_init(MainWindow); //Init The Main Windows of Interface with A title. The window is center in the middle of the screen.
  Menubar = gtk_menu_bar_new();//init Menubar
  Align_button2 = gtk_alignment_new(0,0,1,1);//set alignement 2 for the menubar
  //Align_button1 = gtk_alignment_new( 0.05,0.1,0.1,0.05 ); set alignement 1 
  button1 = initbutton(button1,"close");//init button test
  //fin init
  
  //prgm
  gtk_container_add(GTK_CONTAINER(MainWindow),GtkHbox);
  // gtk_container_add(GTK_CONTAINER(Align_button1),button1);
  gtk_container_add(GTK_CONTAINER(Align_button2),Menubar);
  gtk_box_pack_start(GTK_BOX(GtkHbox),Align_button2,FALSE,TRUE,0);
  gtk_widget_show_all(MainWindow);
  //fin prgm  

  //signal
  // gtk_signal_connect (GTK_OBJECT(test), "clicked",GTK_SIGNAL_FUNC (cb_quit), NULL); // Appelle la function lorsque l'on clique surle bouton test
  // gtk_signal_connect (GTK_OBJECT(button1)
  gtk_widget_show_all(MainWindow);
  g_signal_connect(G_OBJECT(MainWindow), "destroy", G_CALLBACK(cb_quit), NULL);
  gtk_main();
  return EXIT_SUCCESS;
}
