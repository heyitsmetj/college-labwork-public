package com.example.te2202a4seta5;

import android.os.Bundle;
import android.widget.DatePicker;
import android.widget.ImageView;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    DatePicker datePicker;
    ImageView imageView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        datePicker = findViewById(R.id.datePicker);
        imageView = findViewById(R.id.imageView);

        datePicker.init(datePicker.getYear(),
                datePicker.getMonth(),
                datePicker.getDayOfMonth(),

                new DatePicker.OnDateChangedListener() {
                    @Override
                    public void onDateChanged(DatePicker view, int year, int month, int day) {

                        month = month + 1; // month starts from 0

                        // NEW YEAR
                        if(day == 1 && month == 1)
                            imageView.setImageResource(R.drawable.newyear);

                            // INDEPENDENCE DAY
                        else if(day == 15 && month == 8)
                            imageView.setImageResource(R.drawable.independence);

                            // CHRISTMAS
                        else if(day == 25 && month == 12)
                            imageView.setImageResource(R.drawable.christmas);

                            // DEFAULT
                        else
                            imageView.setImageResource(R.drawable.ic_launcher_background);
                    }
                });
    }
}