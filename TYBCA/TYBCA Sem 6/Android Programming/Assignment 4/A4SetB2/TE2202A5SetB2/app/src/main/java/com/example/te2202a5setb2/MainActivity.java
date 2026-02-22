package com.example.te2202a5setb2;

import android.os.Bundle;
import android.util.Patterns;
import android.widget.*;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    EditText name,email,password,age,mobile;
    Button register;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        name = findViewById(R.id.etName);
        email = findViewById(R.id.etEmail);
        password = findViewById(R.id.etPassword);
        age = findViewById(R.id.etAge);
        mobile = findViewById(R.id.etMobile);
        register = findViewById(R.id.btnRegister);

        register.setOnClickListener(v -> validate());
    }

    void validate(){

        String n=name.getText().toString();
        String e=email.getText().toString();
        String p=password.getText().toString();
        String a=age.getText().toString();
        String m=mobile.getText().toString();

        String msg;

        if(n.isEmpty())
            msg="Enter Name";

        else if(!Patterns.EMAIL_ADDRESS.matcher(e).matches())
            msg="Invalid Email";

        else if(p.length()<6)
            msg="Password must be 6 characters";

        else if(a.isEmpty() || Integer.parseInt(a)<18)
            msg="Age must be 18+";

        else if(m.length()!=10)
            msg="Invalid Mobile Number";

        else
            msg="Registration Successful";

        ResultDialog dialog = new ResultDialog(msg);
        dialog.show(getSupportFragmentManager(),"result");
    }
}