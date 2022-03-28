<template>
  <v-app id="inspire">
    <v-main>
      <v-container class="fill-height" fluid>
        <v-row align="center" justify="center">
          <v-col cols="12" sm="8" md="8">
            <v-card class="elevation-12">
                  <v-row class="fill-height">
                    <v-col cols="12" md="8">
                      <v-card-text class="mt-12">
                        <h1 class="text-center display-2 teal--text">Create Account</h1>
                          <v-form>
                          <v-text-field
                            id="email"
                            label="Email"
                            name="email"
                            prepend-icon="person"
                            type="text"
                            color="teal"
                            autocomplete="off"
                            required
                          />
                          <v-text-field
                            id="password"
                            label="Password"
                            name="password"
                            prepend-icon="lock"
                            type="password"
                            color="teal"
                          />
                          <br>
                          <div class="text-center mt-n5">
                            <v-btn rounded color="teal" dark>REGISTER</v-btn>
                          </div>
                        </v-form>
                      </v-card-text>
                    </v-col>
                    <v-col cols="12" md="4" class="teal">
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

</script>