package com.pandurski.bettingtips;

import android.content.Context;
import android.graphics.drawable.Drawable;
import android.support.v7.app.AppCompatActivity;
import android.widget.ImageView;
import android.widget.Switch;
import android.widget.TextView;

import com.google.firebase.database.DataSnapshot;

import java.util.ArrayList;

/**
 * Created by default on 3/20/18.
 */

public class InitializeTips implements IInitializeTxtView{

    TextView date;
    ArrayList<TextView> league;
    {
        league = new ArrayList<>();
    }

    ArrayList<TextView> match_info;
    {
        match_info = new ArrayList<>();
    }

    ArrayList<TextView> predictions;
    {
        predictions = new ArrayList<>();
    }

    ArrayList<ImageView> league_flags;
    {
        league_flags = new ArrayList<>();
    }

    ArrayList<ImageView> result;
    {
        result = new ArrayList<>();
    }

    private Context context;
    public InitializeTips(Context context)
    {
        this.context = context;
    }

    @Override
    public void setLeague()
    {
        AppCompatActivity activity = (AppCompatActivity) context;

        league.add((TextView) activity.findViewById(R.id.league_one));
        league.add((TextView) activity.findViewById(R.id.league_two));
        league.add((TextView) activity.findViewById(R.id.league_three));
        league.add((TextView) activity.findViewById(R.id.league_four));
    }

    @Override
    public void setMatch_info()
    {
        AppCompatActivity activity = (AppCompatActivity) context;

        match_info.add((TextView) activity.findViewById(R.id.match_information_one));
        match_info.add((TextView) activity.findViewById(R.id.match_information_two));
        match_info.add((TextView) activity.findViewById(R.id.match_information_three));
        match_info.add((TextView) activity.findViewById(R.id.match_information_four));
    }

    @Override
    public void setPredictions()
    {
        AppCompatActivity activity = (AppCompatActivity) context;

        predictions.add((TextView) activity.findViewById(R.id.prediction_one));
        predictions.add((TextView) activity.findViewById(R.id.prediction_two));
        predictions.add((TextView) activity.findViewById(R.id.prediction_three));
        predictions.add((TextView) activity.findViewById(R.id.prediction_four));
    }

    @Override
    public void setLeagueFlags()
    {
        AppCompatActivity activity = (AppCompatActivity) context;

        league_flags.add((ImageView) activity.findViewById(R.id.league_flag_one));
        league_flags.add((ImageView) activity.findViewById(R.id.league_flag_two));
        league_flags.add((ImageView) activity.findViewById(R.id.league_flag_three));
        league_flags.add((ImageView) activity.findViewById(R.id.league_flag_four));
    }

    @Override
    public void setResults()
    {
        AppCompatActivity activity = (AppCompatActivity) context;

        result.add((ImageView) activity.findViewById(R.id.prediction_result_one));
        result.add((ImageView) activity.findViewById(R.id.prediction_result_two));
        result.add((ImageView) activity.findViewById(R.id.prediction_result_three));
        result.add((ImageView) activity.findViewById(R.id.prediction_result_four));
    }

    public void showData(DataSnapshot dataSnapshot) {
        int i = 0;
        String str_date = "";
        for(DataSnapshot ds : dataSnapshot.getChildren())
        {
            Prediction tip = ds.getValue(Prediction.class);

            league.get(i).setText(tip.league);
            match_info.get(i).setText(tip.match_info);
            predictions.get(i).setText(tip.prediction);
            league_flags.get(i).setImageDrawable(StringToDrawable(tip.league));
            result.get(i).setImageDrawable(StringToDrawable(tip.result));
            i++;
            str_date = tip.date;
        }
        AppCompatActivity activity = (AppCompatActivity) context;
        TextView date = (TextView) activity.findViewById(R.id.date_todays_tips);
        date.setText(str_date);

    }

    public void Initialize()
    {
        setLeague();
        setMatch_info();
        setPredictions();
        setLeagueFlags();
        setResults();
    }

    private Drawable StringToDrawable( String league_str)
    {
        AppCompatActivity activity = (AppCompatActivity) context;
        Drawable img;
        switch(league_str)
        {
            case "Spain":
                img = activity.getDrawable(R.drawable.spain);
                break;
            case "England":
                img = activity.getDrawable(R.drawable.england);
                break;
            case "Italy":
                img = activity.getDrawable(R.drawable.italy);
                break;
            case "France":
                img = activity.getDrawable(R.drawable.france);
                break;
            case "Germany":
                img = activity.getDrawable(R.drawable.germany);
                break;
            case "Correct":
                img = activity.getDrawable(R.drawable.correct);
                break;
            case "Incorrect":
                img = activity.getDrawable(R.drawable.inncorrect);
                break;
            case "Transperant":
                img = activity.getDrawable(R.drawable.transp);
                break;
            default:
                img = activity.getDrawable(R.drawable.england);
                break;
        }

        return img;
    }

}
