<template>
  <v-app id="inspire">
    <v-main>
      <v-container class="fill-height" style="width: 100%" fluid>
        <v-row align="center" justify="center">
          <v-col cols="12" sm="8" md="8">
            <v-card class="elevation-12">
                  <v-row class="fill-height">
                    <v-col cols="12" md="8">
                      <v-card-text class="mt-12">
                        <h1 class="text-center display-2 light-green--text text--darken-1">Create Account</h1>
                          <v-form>
                            <v-row>
                              <v-col
                                cols="12"
                                sm="5"
                                md="3"
                              >
                                <v-text-field
                                  id="firstname"
                                  label="Firstname"
                                  name="Firstname"
                                  prepend-icon="person"
                                  type="Firstname"
                                  color="light-green darken-1"
                                ></v-text-field>
                              </v-col>

                              <v-col
                                cols="12"
                                sm="7"
                                md="6"
                              >
                                <v-text-field
                                  id="lastname"
                                  label="Lastname"
                                  name="Lastname"
                                  type="Lastname"
                                  color="light-green darken-1"
                                ></v-text-field>
                              </v-col>
                            </v-row>
                          <v-text-field
                            id="email"
                            rule="emailRules"
                            label="Email"
                            name="email"
                            prepend-icon="email"
                            type="text"
                            color="light-green darken-1"
                            autocomplete="off"
                            required
                          />
                          <v-text-field
                            id="password"
                            label="Password"
                            name="password"
                            prepend-icon="lock"
                            type="password"
                            color="light-green darken-1"
                          />
                          <v-text-field
                            id="phone"
                            label="Phone"
                            name="Phone"
                            prepend-icon="phone"
                            type="Phone"
                            color="light-green darken-1"
                          />
                          <v-text-field
                            id="address"
                            label="Address"
                            name="Address"
                            prepend-icon="mdi-map-marker"
                            type="Address"
                            color="light-green darken-1"
                          />
                          <br>
                          <div class="text-center mt-n5">
                            <v-btn rounded color="light-green darken-1" dark>REGISTER</v-btn>
                          </div>
                        </v-form>
                      </v-card-text>
                    </v-col>
                    <v-col cols="12" md="4" class="light-green darken-1">
                      <v-card-text class="white--text mt-12">
                        <h1 class="text-center display-1">Have an account?</h1>
                        <br>
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
  import axios from "axios";
  export default {
    methods:{
      submitRegister(){
        let formData = {
          email: document.getElementById("email").value,
          password: document.getElementById("password").value,
          fname: document.getElementById("firstname").value,
          lname: document.getElementById("lastname").value,
          phone: document.getElementById("phone").value,
          address: document.getElementById("address").value
        };
        axios.post("http://localhost:3000/api/user/register", formData).then((res) => {
          console.log(JSON.stringify(res.data.message));
        });
      }
    },
  }
  data: () => ({
    valid: false,
    email: '',
    emailRules: [
      v => !!v || 'E-mail is required',
      v => /.+@.+/.test(v) || 'E-mail must be valid',
    ],
  });
</script>