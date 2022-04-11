<template>
  <v-dialog v-model="dialog" persistent max-width="600px">
    <template v-slot:activator="{ on, attrs }">
      <v-btn color="success" dark rounded small v-bind="attrs" v-on="on">
        <v-icon left> mdi-account-plus </v-icon>
        Add
      </v-btn>
    </template>
    <v-card color="blue-grey darken-3">
      <v-form @submit.prevent="addAccount" id="addaccount-form">
      <v-toolbar rounded="" class="cyan darken-1">
        <v-card-title
          class="font-weight-bold text-h5 blue-grey--text text--darken-3"
        >
          <span class="text-h5">Add account</span>
        </v-card-title>
      </v-toolbar>
      <v-card-text>
        <v-container>
          <v-row>
            <v-col>
              <v-text-field
                dark
                label="Account name"
                name="Account name"
                v-model="addAccountName"
                prepend-icon="person"
                color="cyan darken-1"
                autocomplete="off"
                required
              ></v-text-field>
            </v-col>
          </v-row>
        </v-container>
      </v-card-text>
      <v-card-actions>
        <v-spacer></v-spacer>
        <v-btn color="cyan darken-1" text @click="dialog = false">
          Close
        </v-btn>
        <v-btn type="submit" form="addaccount-form" color="cyan darken-1" text @click="dialog = false"> Add </v-btn>
      </v-card-actions>
      </v-form>
    </v-card>
  </v-dialog>
</template>

<script>
import axios from "../axios"
export default {
  data: () => ({
    dialog: false,
    addAccountName: ""
  }),
  methods:{
    addAccount() {
        console.log(this.addAccountName);
        axios.post("/api/account", { name: this.addAccountName }).then((response) => {
            if (response.data.status === "success") {
            this.$router.go();
            }
        });
    },
  }
};
</script>