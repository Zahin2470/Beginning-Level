const stompClient = new StompJs.Client({
  brokerURL: "ws://localhost:8080/gs-guide-websocket",
});

stompClient.onConnect = (frame) => {
  setConnected(true);
  console.log("Connected: " + frame);
  stompClient.subscribe("/topic/greetings", (greeting) => {
    showGreeting(JSON.parse(greeting.body).content);
  });

  stompClient.subscribe(`/topic/greetings2`, (greeting2) => {
    showGreeting(JSON.parse(greeting2.body));
  });

  stompClient.subscribe("/topic/login", (login) => {
    showGreeting(JSON.parse(login.body));
  });
};

stompClient.onWebSocketError = (error) => {
  console.error("Error with websocket", error);
};

stompClient.onStompError = (frame) => {
  console.error("Broker reported error: " + frame.headers["message"]);
  console.error("Additional details: " + frame.body);
};

function setConnected(connected) {
  $("#connect").prop("disabled", connected);
  $("#disconnect").prop("disabled", !connected);
  // if (connected) {
  //   $("#conversation").show();
  // } else {
  //   $("#conversation").hide();
  // }
  // $("#greetings").html("");
}

function connect() {
  stompClient.activate();
}

function disconnect() {
  stompClient.deactivate();
  setConnected(false);
  console.log("Disconnected");
}

function sendName() {
  console.log("activated!!");
  stompClient.publish({
    destination: "/app/hello",
    body: JSON.stringify({ name: $("#name").val() }),
  });
}

function sendMessage() {
  console.log("activated!!");
  stompClient.publish({
    destination: "/app/message",
    body: JSON.stringify({
      mess: $("#message").val(),
      sentUserId: sessionStorage.getItem("id"),
    }),
  });
}

{
  /* <div class="message-row you-message">
          <div class="message-content">
            <div class="message-text">Lorem ipsum dolor sit amet</div>
            <div class="message-time">Apr 16</div>
          </div>
        </div> */
}

function showGreeting(message) {
  console.log(message);
  $("#chat-message-list").append(
    `
    
    <div class="message-row ${
      sessionStorage.getItem("id") == message.id
        ? "other-message"
        : "you-message"
    } ">
    <div class="message-content">
      <div class="message-text">${message.mess}</div>
      <div class="message-time">${message.date}</div>
    </div>
  </div>
  `
  );
}

// const successToast = Toastify({
//   text: "User was added successfully! Reloading the list...",
//   duration: 1000,
// });

// const errorToast = Toastify({
//   text: "User already exist!!!",
//   duration: 1000,
// });

function login() {
  console.log("Hi!");
  fetch("http://localhost:8080/login/", {
    method: "POST",
    body: JSON.stringify({
      mobile: "",
      email: $("#email").val(),
      password: $("#password").val(),

      name: "",
      // username: $("#username").val(),
      // password: $("#password").val(),
      // title: "Fix my bugs",
      // completed: false,
    }),
    headers: {
      "Content-type": "application/json; charset=UTF-8",
    },
  })
    .then((response) =>
      // console.log(response);
      {
        return response.json();
      }
    )
    .then((data) => {
      console.log(data);
      if (data.status == "on") {
        // Toastify("Congratulations!!");
        // successToast();
        sessionStorage.setItem("status", "loggedIn");
        sessionStorage.setItem("email", data.email);
        sessionStorage.setItem("mobile", data.mobile);
        sessionStorage.setItem("name", data.name);
        sessionStorage.setItem("id", data.id);
        // successToast();
        location.replace("http://localhost:8080/");
      } else {
        errorToast.errorToast();
      }
    });
  // .then((response) => {
  //   response.json();
  // })
  // .then((json) => {
  //   console.log("json " + json);
  //   // jQuery(window).load(function () {

  //   // });
  //   // $(window).on("load", function () {
  //   // sessionStorage.setItem("status", "loggedIn");
  //   // });

  //   // location.replace("http://localhost:8080/");
  // });
  // console.log("heu");
  // stompClient.publish({
  //   destination: "/app/login",
  //   // body: JSON.stringify({ mess: $("#message").val() }),
  //   body: JSON.stringify({
  //     username: $("#username").val(),
  //     password: $("#password").val(),
  //     // title: "Fix my bugs",
  //     // completed: false,
  //   }),
  // });
}

// // do login
// async function login(req, res, next) {
//   console.log("Hello");
//   try {
//     // find a user who has this email/username
//     const user = await User.findOne({
//       $or: [{ email: req.body.username }, { mobile: req.body.username }],
//     });

//     if (user && user._id) {
//       const isValidPassword = await bcrypt.compare(
//         req.body.password,
//         user.password
//       );

//       if (isValidPassword) {
//         // prepare the user object to generate token
//         const userObject = {
//           userid: user._id,
//           username: user.name,
//           email: user.email,
//           avatar: user.avatar || null,
//           role: user.role || "user",
//         };

//         // generate token
//         const token = jwt.sign(userObject, process.env.JWT_SECRET, {
//           expiresIn: process.env.JWT_EXPIRY,
//         });

//         // set cookie
//         res.cookie(process.env.COOKIE_NAME, token, {
//           maxAge: process.env.JWT_EXPIRY,
//           httpOnly: true,
//           signed: true,
//         });

//         // set logged in user local identifier
//         res.locals.loggedInUser = userObject;

//         res.redirect("/index.html");
//       } else {
//         throw createError("Login failed! Please try again.");
//       }
//     } else {
//       throw createError("Login failed! Please try again.");
//     }
//   } catch (err) {
//     res.render("index", {
//       data: {
//         username: req.body.username,
//       },
//       errors: {
//         common: {
//           msg: err.message,
//         },
//       },
//     });
//   }
// }

$(function () {
  $("form").on("submit", (e) => e.preventDefault());
  $("#connect").click(() => connect());
  $("#disconnect").click(() => disconnect());
  $("#send").click(() => sendName());
  $("#message2").click(() => sendMessage());
  $("#login").click(() => login());
});
