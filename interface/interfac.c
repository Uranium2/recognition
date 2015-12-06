#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>



//Fction CALLBACK
void cb_quit(GtkWidget *Window)
{
  gtk_main_quit();
  (void)Window;
}


//FCTion 
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
  //BOX
  GtkWidget *GtkHbox = NULL; 
  GtkWidget *GtkVbox = NULL; 

  //MainWindow
  GtkWidget *MainWindow = NULL;
  
  //button and allignement
  GtkWidget *button1 = NULL; // appartient a la vertical box1/2 de la horizontal box 2/2
  //GtkWidget *Align_button1 = NULL;
  //GtkWidget *Align_button2 = NULL;
  GtkWidget *button2 = NULL;
  GtkWidget *button3 = NULL;
  GtkWidget *label = NULL;
  //GtkWidget *Align_button3 = NULL;


  //fin declaration widget

  //init

  gtk_init(&argc, &argv);//init GTK
  
  //init box
  GtkVbox = gtk_vbox_new(TRUE,0);
  GtkHbox = gtk_hbox_new(TRUE,0);

  MainWindow = MainWindow_init(MainWindow); //Init The Main Windows of Interface with A title. The window is center in the middle of the screen.

  //init button
  label = gtk_label_new("[No Image]");
  button1 = initbutton(button1,"open");//init button test
  button2 = initbutton(button2,"process");
  button3 = initbutton(button3,"save");

  //PRGM
  gtk_container_add(GTK_CONTAINER(MainWindow),GtkHbox);
  gtk_box_pack_start(GTK_BOX(GtkHbox),GtkVbox,TRUE,FALSE,0);
  gtk_box_pack_start(GTK_BOX(GtkHbox),label,TRUE,FALSE,0);
  gtk_box_pack_start(GTK_BOX(GtkVbox),button1,FALSE,FALSE,0);
  gtk_box_pack_start(GTK_BOX(GtkVbox),button2,FALSE,FALSE,0);
  gtk_box_pack_start(GTK_BOX(GtkVbox),button3,FALSE,FALSE,0);
  
 
  
    
  //SIGNAL
  gtk_signal_connect (GTK_OBJECT(button1), "clicked",GTK_SIGNAL_FUNC (cb_quit), NULL); // Appelle la function lorsque l'on clique surle bouton test
  gtk_signal_connect (GTK_OBJECT(button2), "clicked",GTK_SIGNAL_FUNC (cb_quit), NULL);
  gtk_signal_connect (GTK_OBJECT(button3), "clicked",GTK_SIGNAL_FUNC (cb_quit), NULL);
  gtk_widget_show_all(MainWindow);
  g_signal_connect(G_OBJECT(MainWindow), "destroy", G_CALLBACK(cb_quit), NULL);
  gtk_main();


  return EXIT_SUCCESS;
}
