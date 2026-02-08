package com.example.te2202a2setb2;

import android.app.DatePickerDialog;
import android.content.Intent;
import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;

import androidx.appcompat.app.AppCompatActivity;

import java.util.Calendar;

public class MainActivity extends AppCompatActivity {

    EditText f, m, l, d, a, e;
    Button btn;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        f = findViewById(R.id.edtFname);
        m = findViewById(R.id.edtMname);
        l = findViewById(R.id.edtLname);
        d = findViewById(R.id.edtDob);
        a = findViewById(R.id.edtAddress);
        e = findViewById(R.id.edtEmail);
        btn = findViewById(R.id.btnSubmit);

        // DatePicker for DOB
        d.setOnClickListener(v -> {
            Calendar c = Calendar.getInstance();
            int day = c.get(Calendar.DAY_OF_MONTH);
            int month = c.get(Calendar.MONTH);
            int year = c.get(Calendar.YEAR);

            DatePickerDialog dp = new DatePickerDialog(
                    MainActivity.this,
                    (view, y, mth, dOfMonth) ->
                            d.setText(dOfMonth + "/" + (mth + 1) + "/" + y),
                    year, month, day
            );
            dp.show();
        });

        btn.setOnClickListener(v -> {
            Intent i = new Intent(MainActivity.this, SecondActivity.class);
            i.putExtra("fname", f.getText().toString());
            i.putExtra("mname", m.getText().toString());
            i.putExtra("lname", l.getText().toString());
            i.putExtra("dob", d.getText().toString());
            i.putExtra("addr", a.getText().toString());
            i.putExtra("email", e.getText().toString());
            startActivity(i);
        });
    }
}
