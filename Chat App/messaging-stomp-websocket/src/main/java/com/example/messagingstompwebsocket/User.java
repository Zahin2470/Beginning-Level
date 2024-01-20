package com.example.messagingstompwebsocket;


import java.io.Serializable;
import java.util.ArrayList;

public class User implements Serializable {
    private String id;
    private String username;
    private String password;

    private String email;

    private String mobile;

    private String name;

    private String status;



    private ArrayList<Conversation> conversationArrayList;
    private int numberOfConversation = 0;

    public User(){
    }

    public User(String m, String e, String p, String n){
        this.id = e + m + "2023";
        this.username = e;
        this.email = e;
        this.name = n;
        this.mobile = m;
        this.password = p;

    }

    public void addConversation(Conversation c){
        this.conversationArrayList.add(c);
        this.numberOfConversation++;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getMobile() {
        return mobile;
    }

    public void setMobile(String mobile) {
        this.mobile = mobile;
    }

    public User(User another) {
        this.id  = another.id;
        this.email = another.getEmail(); // you can access
        this.mobile = another.getMobile();
        this.name = another.getName();
        this.password = another.getPassword();
        this.username = another.getUsername();
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public void display(){
        System.out.println("Id: " + this.id + " " + this.name + " " + this.mobile + " "  + this.email + " "+ this.password);
    }

    public String getStatus() {
        return status;
    }

    public void setStatus(String status) {
        this.status = status;
    }

    public String getId() {
        return id;
    }


}