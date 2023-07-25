package com.example.myapplication;

import android.content.DialogInterface;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;

import android.os.Bundle;
import android.view.GestureDetector;
import android.view.MotionEvent;
import android.view.View;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.TextView;
import android.widget.Toast;


public class MainActivity extends AppCompatActivity {
    private EditText inputEditText;
    private CheckBox degreesCheckBox;
    private RadioButton thRadioButton;
    private TextView resultTextView;

    private GestureDetector gesture_detector;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        inputEditText = findViewById(R.id.input_edit_text);
        degreesCheckBox = findViewById(R.id.degrees_check_box);
        thRadioButton = findViewById(R.id.th_radio_button);
        resultTextView = findViewById(R.id.result_text_view);
        gesture_detector = new GestureDetector(this, new MyGestureListener());

        findViewById(R.id.calculate_button).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                calculateResult();
            }
        });
    }

    private void calculateResult() {
        String inputText = inputEditText.getText().toString().trim();
        if (inputText.isEmpty()) {
            Toast.makeText(this, "Please enter a number", Toast.LENGTH_SHORT).show();
            return;
        }

        double inputNumber = Double.parseDouble(inputText);
        if (inputNumber <= 0) {
            Toast.makeText(this, "Invalid input value", Toast.LENGTH_SHORT).show();
            return;
        }

        double result;
        if (thRadioButton.isChecked()) {
            result = Math.tanh(getInputInRadians());
        } else {
            Toast.makeText(this, "Invalid operation", Toast.LENGTH_SHORT).show();
            return;
        }

        if (Double.isNaN(result) || Double.isInfinite(result)) {
            Toast.makeText(this, "Invalid operation", Toast.LENGTH_SHORT).show();
            return;
        }

        resultTextView.setText(String.format("%.4f", result));
    }

    private double getInputInRadians() {
        double inputNumber = Double.parseDouble(inputEditText.getText().toString().trim());
        if (degreesCheckBox.isChecked()) {
            return Math.toRadians(inputNumber);
        } else {
            return inputNumber;
        }
    }

    @Override
    public boolean onTouchEvent(MotionEvent event) {
        gesture_detector.onTouchEvent(event);
        return super.onTouchEvent(event);
    }

    private class MyGestureListener extends GestureDetector.SimpleOnGestureListener {
        private static final int SWIPE_THRESHOLD = 100;
        private static final int SWIPE_VELOCITY_THRESHOLD = 100;

        @Override
        public boolean onFling(MotionEvent event1, MotionEvent event2, float velocityX, float velocityY) {
            float diffX = event2.getX() - event1.getX();
            float diffY = event2.getY() - event1.getY();

            if (Math.abs(diffX) > Math.abs(diffY)) {
                if (Math.abs(diffX) > SWIPE_THRESHOLD && Math.abs(velocityX) > SWIPE_VELOCITY_THRESHOLD) {
                    if (diffX > 0) {

                        AlertDialog alertDialog = new AlertDialog.Builder(MainActivity.this)
                                .setIcon(android.R.drawable.ic_dialog_alert)
                                .setTitle("Are you sure to Exit")
                                .setMessage("Exiting will call finish() method")
                                .setPositiveButton("Yes", new DialogInterface.OnClickListener() {
                                    @Override
                                    public void onClick(DialogInterface dialogInterface, int i) {
                                        //set what would happen when positive button is clicked
                                        finish();
                                    }
                                })
                                .setNegativeButton("No", new DialogInterface.OnClickListener() {
                                    @Override
                                    public void onClick(DialogInterface dialogInterface, int i) {
                                        //set what should happen when negative button is clicked
                                        Toast.makeText(getApplicationContext(),"Nothing Happened",Toast.LENGTH_LONG).show();
                                    }
                                })
                                .show();

                    }
                    return true;
                }
            }
            return false;
        }
    }

}
