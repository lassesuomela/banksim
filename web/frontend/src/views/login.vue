<template>
  <v-app id="inspire">
    <v-main>
      <v-container class="fill-height" fluid>
        <v-row align="center" justify="center">
          <v-col cols="12" sm="8" md="8">
            <v-card class="elevation-12">
                  <v-row>
                    <v-col cols="12" md="8">
                      <v-card-text class="mt-12">
                        <h1
                          class="text-center display-2 blue--text text--accent-3">Login</h1>
                          <v-form @submit.prevent="submitLogin" id="login-form">
                          <v-text-field
                            id="email"
                            label="Email"
                            name="email"
                            prepend-icon="person"
                            type="text"
                            color="blue accent-3"
                            autocomplete="off"
                            required
                          />
                          <v-text-field
                            id="password"
                            label="Password"
                            name="password"
                            prepend-icon="lock"
                            type="password"
                            color="blue accent-3"
                            required
                          />
                          <br>
                          <div class="text-center mt-n5">
                            <v-btn type="submit" rounded color="blue accent-3" dark form="login-form">LOGIN</v-btn>
                          </div>
                        </v-form>
                      </v-card-text>
                    </v-col>
                    <v-col cols="12" md="4" class="blue accent-3">
                      <v-card-text class="white--text mt-12">
                        <h1 class="text-center display-1">Need an account?</h1>
                        <br>
                      </v-card-text>
                      <div class="text-center">
                        <v-btn to="/register" rounded outlined dark>REGISTER</v-btn>
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
import axios from "axios";
export default{
  methods:{
    submitLogin(){
      let formData = {
        email: document.getElementById("email").value,
        password: document.getElementById("password").value
      };
      axios.post("http://localhost:3000/api/user/login", formData).then((res) => {
        console.log(JSON.stringify(res.data.message));
      });
    }
  }
  
};
</script>
