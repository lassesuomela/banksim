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
<<<<<<< HEAD
        <v-toolbar-title class="font-weight-bold text-h5 blue-grey--text text--darken-3">
        Accounts
        </v-toolbar-title>
        <v-spacer></v-spacer>
        <v-dialog v-model="dialog" max-width="500px">
          <v-card color="blue-grey darken-3">
            <v-toolbar rounded="" class="cyan darken-1">
                <v-icon>mdi-person</v-icon>
                <v-card-title class="font-weight-bold text-h5 blue-grey--text text--darken-3">
                    <span class="text-h5">Account you want add</span>
                </v-card-title>
            </v-toolbar>
            <br>
=======
        <v-toolbar-title
          class="font-weight-bold text-h5 blue-grey--text text--darken-3"
        >
          Accounts
        </v-toolbar-title>
        <v-spacer></v-spacer>
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
                class="font-weight-bold text-h5 blue-grey--text text--darken-3">
                <span class="text-h5">Add account</span>
              </v-card-title>
            </v-toolbar>
>>>>>>> 66f6d424859aabe6c7a01994110fa1cd30230585
            <v-card-text>
              <v-container>
                <v-row>
                  <v-col>
<<<<<<< HEAD
                    <v-select v-model="selectType" dark color="cyan darken-1" :items="cardtype" label="Acc" prepend-icon="mdi-account-plus" ></v-select>
=======
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
>>>>>>> 66f6d424859aabe6c7a01994110fa1cd30230585
                  </v-col>
                </v-row>
              </v-container>
            </v-card-text>
<<<<<<< HEAD
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

        
      <accadd/>
=======
            <v-card-actions>
              <v-spacer></v-spacer>
              <v-btn color="cyan darken-1" text @click="dialog = false">
                Close
              </v-btn>
              <v-btn type="submit" form="addaccount-form" color="cyan darken-1" text @click="dialog = false">
                Add
              </v-btn>
            </v-card-actions>
            </v-form>
          </v-card>
        </v-dialog>
>>>>>>> 66f6d424859aabe6c7a01994110fa1cd30230585
      </v-toolbar>
    </template>
    <template v-slot:[`item.actions`]="{ item }">
      <v-icon small class="mr-2" @click="editItem(item)">mdi-account-plus</v-icon>
      <v-icon small @click="deleteItem(item)">mdi-delete</v-icon>
    </template>
    
  </v-data-table>
</template>

<script>
<<<<<<< HEAD
  import axios from "../axios"
  import accadd from './accadd.vue'
  export default {
  components: { accadd },

    data: () => ({
      dialog: false,
      dialogDelete: false,
      cardtype: ['acc1', 'acc2'],
      Accounts: [],
      headers: [
        { text: 'Name', align: 'start', sortable: false, value: 'name', },
        { text: 'Account ID', value: 'id' },
        { text: 'Balance €', value: 'balance' },
        { text: 'Actions', value: 'actions', sortable: false },
      ],
      defaultItem: { name: '', id: 0, balance: 0, },
    }),   
    created () {
      this.initialize()
    },
    methods: {
        editItem (item) {
        this.dialog = true
      },
      initialize () {
        axios.get("/api/account").then((response) => {
          for(let i=0;i<response.data.length;i++){
            this.Accounts.push({name:response.data[i].name,id:response.data[i].account_ID,balance:response.data[i].balance});
          }
        });
      },
      deleteItem(item){
        axios.delete("/api/account",{id:Number(item.id)}).then((response) => {

        });
      }
=======
import axios from "../axios";
export default {
  data: () => ({
    dialog: false,
    dialogDelete: false,
    addAccountName: "",
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
    addAccount(){
      axios.post("/api/account", {name:this.addAccountName}).then((response) => {
        if(response.data.status === "success"){
          this.$router.go();
        }
      });
>>>>>>> 66f6d424859aabe6c7a01994110fa1cd30230585
    },
    deleteItem(item) {
      axios.delete("/api/account", {data:{id:item.id}} ).then((response) => {
        if(response.data.status === "success"){
          this.$router.go();
        }
      });
    },
  },
};
</script>