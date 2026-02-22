package com.example.te2202a4seta3;

import android.app.DatePickerDialog;
import android.app.TimePickerDialog;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

import java.util.Calendar;

public class MainActivity extends AppCompatActivity {

    TextView txtDate, txtTime;
    Button btnDate, btnTime;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        txtDate = findViewById(R.id.txtDate);
        txtTime = findViewById(R.id.txtTime);
        btnDate = findViewById(R.id.btnDate);
        btnTime = findViewById(R.id.btnTime);

        // DATE PICKER
        btnDate.setOnClickListener(v -> {

            Calendar c = Calendar.getInstance();
            int year = c.get(Calendar.YEAR);
            int month = c.get(Calendar.MONTH);
            int day = c.get(Calendar.DAY_OF_MONTH);

            DatePickerDialog dp = new DatePickerDialog(MainActivity.this,
                    (view, y, m, d) -> txtDate.setText("Date: " + d + "/" + (m+1) + "/" + y),
                    year, month, day);

            dp.show();
        });

        // TIME PICKER
        btnTime.setOnClickListener(v -> {

            Calendar c = Calendar.getInstance();
            int hour = c.get(Calendar.HOUR_OF_DAY);
            int minute = c.get(Calendar.MINUTE);

            TimePickerDialog tp = new TimePickerDialog(MainActivity.this,
                    (view, h, m) -> txtTime.setText("Time: " + h + ":" + m),
                    hour, minute, true);

            tp.show();
        });
    }
}
