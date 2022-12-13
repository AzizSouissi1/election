#include <gtk/gtk.h>


void
on_saif_radiobutton_oui_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_saif_radiobutton_non_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

gboolean
on_saif_window_aff_focus_in_event      (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data);

void
on_saif_treeview_aff_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_saif_button_aff_rech_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_saif_button_aff_sup_clicked         (GtkButton       *widget,
                                        gpointer         user_data);

void
on_saif_button_aff_act_clicked         (GtkButton       *objet,
                                        gpointer         user_data);

void
on_saif_button_aff_ret_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_saif_button_aff_mod_clicked         (GtkButton       *widget,
                                        gpointer         user_data);

void
on_saif_button_aff_aj_clicked          (GtkButton       *objet,
                                        gpointer         user_data);

void
on_saif_button_aj_conf_clicked         (GtkButton       *objet,
                                        gpointer         user_data);

void
on_saif_button_aj_ret_clicked          (GtkButton       *objet,
                                        gpointer         user_data);

void
on_saif_checkbutton_aj_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

gboolean
on_saif_window_mod_focus_in_event      (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data);

void
on_saif_button_md_conf_clicked         (GtkButton       *objet,
                                        gpointer         user_data);

void
on_saif_button_md_ret_clicked          (GtkButton       *objet,
                                        gpointer         user_data);

void
on_saif_checkbutton_mod_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_saif_button_app_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_saif_entry_aff_cher_changed         (GtkEditable     *editable,
                                        gpointer         user_data);

void
on_saif_button_ret_stat_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_saif_button_aff_stat_clicked        (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_statistique_focus_in_event          (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data);
