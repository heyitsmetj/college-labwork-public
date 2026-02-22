package com.example.te2202a4setb1;

import android.content.Intent;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.os.Environment;
import android.provider.Settings;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

import java.io.File;
import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {

    ListView listView;
    File currentDir;
    ArrayList<String> items;
    ArrayList<File> files;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        listView = findViewById(R.id.listView);

        checkPermission();

        listView.setOnItemClickListener((parent, view, position, id) -> {

            File selected = files.get(position);

            if (selected.isDirectory()) {
                openDirectory(selected);
            } else {
                Toast.makeText(this,
                        "File: " + selected.getName(),
                        Toast.LENGTH_SHORT).show();
            }
        });
    }

    // Ask for All Files Access permission
    void checkPermission() {

        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.R) {

            if (!Environment.isExternalStorageManager()) {

                Intent intent = new Intent(Settings.ACTION_MANAGE_APP_ALL_FILES_ACCESS_PERMISSION);
                intent.setData(Uri.parse("package:" + getPackageName()));
                startActivity(intent);

                Toast.makeText(this,
                        "Please Allow 'All Files Access' and reopen app",
                        Toast.LENGTH_LONG).show();

            } else {
                openRoot();
            }

        } else {
            openRoot();
        }
    }

    // Open storage root
    void openRoot() {
        File path = Environment.getExternalStorageDirectory();
        openDirectory(path);
    }

    // Show files in ListView
    void openDirectory(File dir) {

        currentDir = dir;
        File[] fileList = dir.listFiles();

        items = new ArrayList<>();
        files = new ArrayList<>();

        if (fileList == null) {
            Toast.makeText(this, "Folder Empty / Access Denied", Toast.LENGTH_SHORT).show();
            return;
        }

        // Back option
        if (dir.getParentFile() != null) {
            items.add(".. (Back)");
            files.add(dir.getParentFile());
        }

        for (File file : fileList) {
            files.add(file);

            if (file.isDirectory())
                items.add("[Folder] " + file.getName());
            else
                items.add(file.getName());
        }

        listView.setAdapter(new ArrayAdapter<>(this,
                android.R.layout.simple_list_item_1, items));
    }
}