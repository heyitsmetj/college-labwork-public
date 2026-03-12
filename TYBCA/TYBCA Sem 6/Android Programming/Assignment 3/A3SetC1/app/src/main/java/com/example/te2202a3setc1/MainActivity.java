package com.example.te2202a3setc1;

import android.os.Bundle;
import android.widget.ArrayAdapter;
import android.widget.Spinner;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    Spinner spinner;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        spinner = findViewById(R.id.spinnerCoffee);

        String[] coffee = {
                "Filter",
                "Americano",
                "Latte",
                "Espresso",
                "Cappuccino",
                "Mocha",
                "Skinny Latte",
                "Espresso Corretto"
        };

        ArrayAdapter<String> adapter =
                new ArrayAdapter<>(this,
                        R.layout.spinner_item,
                        coffee);

        adapter.setDropDownViewResource(R.layout.spinner_item);
        spinner.setAdapter(adapter);
    }
}