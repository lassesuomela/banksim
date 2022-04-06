<template>
  <v-data-table
    :headers="headers"
    dark
    :items="Accounts"
    sort-by="id"
    class="elevation-1 blue-grey darken-3"
  >
    <template v-slot:top>
      <v-toolbar rounded="" class="cyan darken-1">
        <v-toolbar-title
          class="font-weight-bold text-h5 blue-grey--text text--darken-3">
          Accounts
        </v-toolbar-title>
        <v-spacer></v-spacer>
        <v-dialog v-model="dialog" max-width="500px">
          <v-card color="blue-grey darken-3">
            <v-toolbar rounded="" class="cyan darken-1">
              <v-icon>mdi-person</v-icon>
              <v-card-title
                class="font-weight-bold text-h5 blue-grey--text text--darken-3"
              >
                <span class="text-h5">Account you want add</span>
              </v-card-title>
            </v-toolbar>
            <br />
            <v-card-text>
              <v-container>
                <v-row>
                  <v-col>
                    <v-select
                      v-model="selectType"
                      dark
                      color="cyan darken-1"
                      :items="cardtype"
                      label="Acc"
                      prepend-icon="mdi-account-plus"
                    ></v-select>
                  </v-col>
                </v-row>
              </v-container>
            </v-card-text>
            <v-card-actions>
              <v-spacer></v-spacer>
              <v-btn color="cyan darken-1" text @click="dialog = false">
                Close
              </v-btn>
              <v-btn color="cyan darken-1" text @click="dialog = false">
                Save
              </v-btn>
            </v-card-actions>
          </v-card>
        </v-dialog>

        <accadd />
      </v-toolbar>
    </template>
    <template v-slot:[`item.actions`]="{ item }">
      <v-icon small class="mr-2" @click="editItem(item)">mdi-account-plus</v-icon>
      <v-icon small @click="deleteItem(item)">mdi-delete</v-icon>
    </template>
  </v-data-table>
</template>

<script>
import axios from "../axios";
import accadd from "./accadd.vue";
export default {
  components: { accadd },
  data: () => ({
    dialog: false,
    dialogDelete: false,
    addUserEmail: "",
    Accounts: [],
    headers: [
      { text: "Name", align: "start", sortable: false, value: "name" },
      { text: "Account ID", value: "id" },
      { text: "Balance €", value: "balance" },
      { text: "Actions", value: "actions", sortable: false },
    ],
    defaultItem: { name: "", id: 0, balance: 0 },
  }),
  created() {
    this.initialize();
  },
  methods: {
    editItem(item) {
      this.dialog = true;
    },
    initialize() {
      axios.get("/api/account").then((response) => {
        for (let i = 0; i < response.data.length; i++) {
          this.Accounts.push({
            name: response.data[i].name,
            id: response.data[i].account_ID,
            balance: response.data[i].balance,
          });
        }
      });
    },
    addUserToAccount(item){
      axios.post("/account/adduser",{email:this.addUserEmail,account:item.id}).then((response) => {
        if(response.data.status === "success"){
          this.$router.go();
        }
      });
    },
    deleteItem(item) {
      axios.delete("/api/account", { data: { id: item.id } }).then((response) => {
          if (response.data.status === "success") {
            this.$router.go();
          }
        });
    },
  },
};
</script>