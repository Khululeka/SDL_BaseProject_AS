package org.libsdl.app;

//import SDLActivity;

import java.io.IOException;
import java.util.List;
import java.util.LinkedList;


/**
 * Created by rjv on 10-10-2017.
 */

public class HelperFunctions extends SDLActivity
{
    public String [] list_assets(String path, boolean get_directories, boolean get_files) {
        List<String> files = new LinkedList<String>();

        if(path.length() > 1 && path.charAt(path.length()-1) == '/')
            path = path.substring(0, path.length()-1);


        try {
            String [] ls = getAssets().list(path);

            for(String file : ls) {
// Lame problem...Â  AssetManager::list() is super slow (does it unpack the whole apk each time?).
// This is a lame workaround, but assumes files have extensions and directories don't.
                boolean has_dot = file.contains(".");
                if((get_files && has_dot) || (get_directories && !has_dot))
                    files.add(file);

            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        return files.toArray(new String[files.size()]);
    }
}