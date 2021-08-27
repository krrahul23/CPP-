const fun = () => {
  document.getElementById("name").addEventListener(onclick, () => {
    alert("this was hovered.");
  });
  console.log("this was hovered");
};

inputName = "";
password = "";
email = "";
const namefunc = () => {
  inputName = document.getElementById("name").value;
};

const emailFunc = () => {
  email = document.getElementById("email").value;
  console.log(email);
};

const pass = () => {
  password = document.getElementById("password").value;
};
const handleSubmit = () => {
  namefunc();
  pass();

  if (password === "" && inputName === "")
    alert("Please enter email and password");
  else alert("login successful");
};

function onOff1() {
  var s1 = document.getElementById("left");
  var s2 = document.getElementById("right");
  var temp = s1.src;
  s1.src = s2.src;
  s2.src = temp;
  console.log("1");
}
