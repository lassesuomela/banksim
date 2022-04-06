<template>
  <v-app id="inspire">
    <v-main>
      <v-container class="fill-height" fluid>
        <v-row align="center" justify="center">
          <v-col cols="12" sm="8" md="8">
            <v-card class="elevation-12">
              <v-row>
                <v-col cols="12" md="8" class="blue-grey darken-3">
                  <v-card-text class="mt-12">
                    <h1 class="text-center display-2 cyan--text text--darken-1">
                      Login
                    </h1>
                    <v-form @submit.prevent="submitLogin" id="login-form">
                      <v-text-field
                        dark
                        id="email"
                        label="Email"
                        name="email"
                        v-model="email"
                        prepend-icon="person"
                        type="text"
                        color="cyan darken-1"
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
                        color="cyan darken-1"
                        @click:append="show1 = !show1"
                        required
                      />
                      <br />
                      <h5>{{ loginResponse }}</h5>
                      <div class="text-center mt-n5">
                        <v-btn
                          type="submit"
                          rounded
                          color="cyan darken-1"
                          dark
                          form="login-form"
                          >LOGIN</v-btn
                        >
                      </div>
                    </v-form>
                  </v-card-text>
                </v-col>
                <v-col cols="12" md="4" class="cyan darken-1">
                  <v-card-text class="white--text mt-12">
                    <h1 class="text-center display-1">Need an account?</h1>
                    <br />
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
import axios from "../axios";
export default {
  methods: {
    submitLogin() {
      let formData = {
        email: this.email,
        password: this.password,
      };
      axios.post("/api/user/login", formData).then((res) => {
        this.loginResponse = res.data.message;
        if (res.data.status === "success") {
          localStorage.setItem("token", res.data.token);
          window.location.replace("/home");
        }
      });
    },
    isLoggedIn() {
      if (localStorage.getItem("token")) {
        this.$router.replace("/home");
      }
    },
  },
  beforeMount() {
    this.isLoggedIn();
  },
  data() {
    return {
      show1: false,
      email: "",
      password: "",
      loginResponse: "",
    };
  },
};
</script>
<style>
#inspire {
  background-color: #202227;
  background-position: center;
  background-size: inherit;
}
</style>
