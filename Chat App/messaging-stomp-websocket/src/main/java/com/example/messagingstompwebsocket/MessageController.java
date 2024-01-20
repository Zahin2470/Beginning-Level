package com.example.messagingstompwebsocket;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.context.annotation.Bean;
import org.springframework.messaging.handler.annotation.MessageMapping;
import org.springframework.messaging.handler.annotation.SendTo;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.util.HtmlUtils;

import java.text.DateFormat;
import java.time.LocalDate;
import java.time.ZoneId;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;

@Controller
@RestController
public class MessageController {

    @MessageMapping("/message")
    @SendTo("/topic/greetings2")

    public Object greeting2(Message message) throws Exception {
        Thread.sleep(500); // simulated delay
        System.out.println("Hello @!!!!!");
        Map<String, Object> object = new HashMap<>();

        Date date = new Date();
        LocalDate localDate = date.toInstant().atZone(ZoneId.systemDefault()).toLocalDate();
        object.put("mess", message.getMess());
        object.put("id", message.getSentUserId());
        object.put("date", localDate);
        return object;
    }

    @MessageMapping("/message2")
    @SendTo("/secured/{user}")

    public Object secured(Message message) throws Exception {
        Thread.sleep(500); // simulated delay
        System.out.println("Hello Secured @!!!!!");
        Map<String, Object> object = new HashMap<>();

        Date date = new Date();
        LocalDate localDate = date.toInstant().atZone(ZoneId.systemDefault()).toLocalDate();
        object.put("mess", message.getMess());
        object.put("date", localDate);
        return object;
    }
}
