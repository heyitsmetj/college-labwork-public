package com.example.te2202a4seta1;

import android.app.Activity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.TextView;

import java.util.ArrayList;

public class ContactAdapter extends ArrayAdapter<Contact> {

    Activity context;
    ArrayList<Contact> list;

    public ContactAdapter(Activity context, ArrayList<Contact> list) {
        super(context, 0, list);
        this.context = context;
        this.list = list;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {

        LayoutInflater inflater = context.getLayoutInflater();
        View row = inflater.inflate(R.layout.contact_layout, null, true);

        ImageView img = row.findViewById(R.id.imgPhoto);
        TextView name = row.findViewById(R.id.txtName);
        TextView phone = row.findViewById(R.id.txtPhone);
        TextView email = row.findViewById(R.id.txtEmail);

        Contact c = list.get(position);

        img.setImageResource(c.getImage());
        name.setText(c.getName());
        phone.setText(c.getPhone());
        email.setText(c.getEmail());

        return row;
    }
}
