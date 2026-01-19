package com.example.te2202a2setb1;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    EditText edtEmail, edtPassword;
    Button btnLogin;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        edtEmail = findViewById(R.id.edtEmail);
        edtPassword = findViewById(R.id.edtPassword);
        btnLogin = findViewById(R.id.btnLogin);

        btnLogin.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                String email = edtEmail.getText().toString();
                String password = edtPassword.getText().toString();

                if (email.equals("admin") && password.equals("1234")) {
                    Toast.makeText(MainActivity.this,
                            "Login Successful", Toast.LENGTH_SHORT).show();

                    Intent i = new Intent(MainActivity.this, SecondActivity.class);
                    startActivity(i);
                } else {
                    Toast.makeText(MainActivity.this,
                            "Invalid Login", Toast.LENGTH_SHORT).show();
                }
            }
        });
    }
}