#include <stdio.h>
#include <glib.h>
#include <gmodule.h>
#include <string.h>

void
iterator(gpointer key, gpointer value, gpointer user_data) {
    printf(user_data, key, value);
}

int
main(int argc, char **argv) {
    GHashTable *wordtable =  g_hash_table_new(g_str_hash, g_str_equal);
    char s[82];
    //gchar gs[81];
    gchar **words;
    while (fgets(s, 80, stdin)) {
        s[strlen(s) - 1] = '\0';
        if (strlen(s) == 0) {
            break;
        }
        //g_strpcpy(gs, s);
        words = g_strsplit(s, " ", 80);
        if (words != NULL) {
            guint len = g_strv_length(words);
            for (int i = 0; i < len; i++) {
                if (g_hash_table_contains(wordtable, words[i])) {
                    g_hash_table_insert(wordtable, words[i],  GINT_TO_POINTER(GPOINTER_TO_INT(g_hash_table_lookup(wordtable, words[i])) + 1));
                } else {
                     g_hash_table_insert(wordtable, words[i],  GINT_TO_POINTER(1));
                }
            }
        }
        g_strfreev(words);
        
        
    }
    g_hash_table_foreach(wordtable, (GHFunc)iterator, "%s: %d\n");
    g_hash_table_destroy(wordtable);
    return 0;
    
}


