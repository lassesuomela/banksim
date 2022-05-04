<template>
  <v-app id="inspire">
    <v-main>
      <v-container class="fill-height" fluid>
        <v-row align="center" justify="center">
          <v-col cols="12" sm="8" md="8">
            <v-card class="elevation-12">
              <v-row class="fill-height">
                <v-col cols="12" md="8" class="blue-grey darken-3">
                  <v-card-text class="mt-12">
                    <h1
                      class="
                        text-center
                        display-2
                        light-green--text
                        text--darken-1
                      "
                    >
                      Create Account
                    </h1>
                    <v-form @submit.prevent="submitRegister" id="register-form">
                      <v-row>
                        <v-col cols="12" sm="5" md="3">
                          <v-text-field
                            dark
                            id="firstname"
                            label="First name"
                            name="firstname"
                            v-model="fname"
                            prepend-icon="person"
                            type="Firstname"
                            color="light-green darken-1"
                            autocomplete="off"
                          ></v-text-field>
                        </v-col>
                        <v-col cols="12" sm="7" md="6">
                          <v-text-field
                            dark
                            id="lastname"
                            label="Last name"
                            name="lastname"
                            v-model="lname"
                            type="Lastname"
                            color="light-green darken-1"
                            autocomplete="off"
                          ></v-text-field>
                        </v-col>
                      </v-row>
                      <v-text-field
                        dark
                        id="email"
                        :rules="emailRules"
                        label="Email"
                        name="email"
                        v-model="email"
                        prepend-icon="email"
                        type="text"
                        color="light-green darken-1"
                        autocomplete="off"
                        required
                      />
                      <v-text-field
                        dark
                        :append-icon="show1 ? 'mdi-eye' : 'mdi-eye-off'"
                        :type="show1 ? 'text' : 'password'"
                        id="password"
                        label="Password"
                        name="password"
                        v-model="password"
                        prepend-icon="lock"
                        color="light-green darken-1"
                        @click:append="show1 = !show1"
                        required
                      />
                      <v-text-field
                        dark
                        id="phone"
                        label="Phone"
                        name="phone"
                        v-model="phone"
                        prepend-icon="phone"
                        type="Phone"
                        color="light-green darken-1"
                        autocomplete="off"
                      />
                      <v-text-field
                        dark
                        id="address"
                        label="Address"
                        name="address"
                        v-model="address"
                        prepend-icon="mdi-map-marker"
                        type="Address"
                        color="light-green darken-1"
                        autocomplete="off"
                      />
                      <br />
                      <h5>{{ registerResponse }}</h5>
                      <div class="text-center mt-n5">
                        <v-btn
                          type="submit"
                          rounded
                          color="light-green darken-1"
                          dark
                          form="register-form"
                          >REGISTER</v-btn
                        >
                      </div>
                    </v-form>
                  </v-card-text>
                </v-col>
                <v-col cols="12" md="4" class="light-green darken-1">
                  <v-card-text class="white--text mt-12">
                    <h1 class="text-center display-1">Have an account?</h1>
                    <br />
                  </v-card-text>
                  <div class="text-center">
                    <v-btn to="/login" rounded outlined dark>LOGIN</v-btn>
                  </div>
                </v-col>
              </v-row>
            </v-card>
          </v-col>
        </v-row>
      </v-container>
    </v-main>
  </v-app>
</template>

<script>
import axios from "../axios";
export default {
  methods: {
    submitRegister() {
      let formData = {
        email: this.email,
        password: this.password,
        fname: this.fname,
        lname: this.lname,
        phone: this.phone,
        address: this.address,
      };
      axios.post("/api/user/register", formData).then((res) => {
        this.registerResponse = res.data.message;
        if (res.data.status === "success") {
          window.location.replace("/login");
        }
      });
    },
  },
  data() {
    return {
      show1: false,
      email: "",
      password: "",
      fname: "",
      lname: "",
      phone: "",
      address: "",
      registerResponse: "",
      valid: false,
      email: "",
      emailRules: [
        (v) => !!v || "E-mail is required",
        (v) => /.+@.+/.test(v) || "E-mail must be valid",
      ],
    };
  },
};
</script>
