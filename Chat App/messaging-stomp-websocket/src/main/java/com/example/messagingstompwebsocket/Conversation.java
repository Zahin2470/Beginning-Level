package com.example.messagingstompwebsocket;

import java.util.ArrayList;

public class Conversation {
    private int id;


    private ArrayList<Message> messageArrayList;
    public Conversation(){

    }

    public void addMessage(Message m){
        this.messageArrayList.add(m);
    }
    public void setId(int id){
        this.id = id;
    }

    public int getId(){
        return this.id ;
    }


}
