package com.example.te2202a2setc1;

import android.content.Intent;
import android.os.Bundle;
import android.widget.Button;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Button btn = findViewById(R.id.btnNext);

        btn.setOnClickListener(v -> {
            Intent i = new Intent(MainActivity.this, SecondActivity.class);
            startActivity(i);
        });
    }
}
