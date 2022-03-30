import axios from "axios";

var UserInfo = {
    uid: -1,
    fname: "",
    lname: "",
    phone: -1,
    address: "",

    getUserData(){
        axios.get("http://localhost:3000/api/user/info").then((res) => {
            this.uid = res.data.user_ID;
            this.fname = res.data.fname;
            this.lname = res.data.lname;
            this.phone = res.data.phone;
            this.address = res.data.address;
        });
      },
}

export default UserInfo;
