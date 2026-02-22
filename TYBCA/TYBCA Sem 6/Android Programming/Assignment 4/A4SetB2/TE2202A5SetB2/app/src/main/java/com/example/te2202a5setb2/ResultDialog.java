package com.example.te2202a5setb2;

import android.app.Dialog;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.widget.TextView;
import androidx.annotation.NonNull;
import androidx.appcompat.app.AlertDialog;
import androidx.fragment.app.DialogFragment;

public class ResultDialog extends DialogFragment {

    String message;

    public ResultDialog(String msg){
        message = msg;
    }

    @NonNull
    @Override
    public Dialog onCreateDialog(Bundle savedInstanceState) {

        LayoutInflater inflater = requireActivity().getLayoutInflater();
        var view = inflater.inflate(R.layout.dialog_result, null);

        TextView tv = view.findViewById(R.id.tvMessage);
        tv.setText(message);

        return new AlertDialog.Builder(requireActivity())
                .setTitle("Registration Status")
                .setView(view)
                .setPositiveButton("OK", null)
                .create();
    }
}