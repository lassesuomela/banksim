<template>
  <v-data-table
    :headers="headers"
    dark
    :items="Accounts"
    sort-by="Kortti"
    class="elevation-1 blue-grey darken-3"
  >
    <template v-slot:top>
      <v-toolbar
        rounded="2"
        class="cyan darken-1"
      >
        <v-toolbar-title class="font-weight-bold text-h5 blue-grey--text text--darken-3">
        Accounts
        </v-toolbar-title>
        <v-spacer></v-spacer>
       <v-btn rounded small color="success">
       <v-icon left> mdi-account-plus
       </v-icon>
         Add
       </v-btn>

        
      </v-toolbar>
    </template>
    <template v-slot:[`item.actions`]="{ item }">
      <v-icon small @click="deleteItem(item)">mdi-delete</v-icon>
    </template>
  </v-data-table>
</template>

<script>
  export default {
    data: () => ({
      dialog: false,
      dialogDelete: false,
      headers: [
        { text: 'Account', align: 'start', sortable: false, value: 'Account', },
        { text: 'Kortti??', value: 'Kortti' },
        { text: 'Balance €', value: 'Balance' },
        { text: 'Actions', value: 'actions', sortable: false },
      ],
      defaultItem: { Account: '', Kortti: 0, Balance: 0, },
    }),   
    created () {
      this.initialize()
    },
    deleteItem (item) {
        
      },
    methods: {
      initialize () {
        this.Accounts = [
          { Account: 'Account 1', Kortti: 'lkm?', Balance: 6000, },
          { Account: 'Account 2', Kortti: 'ID?', Balance: 5000, },
          { Account: 'Account 3', Kortti: 1, Balance: 1000, },
          { Account: 'Account 4', Kortti: 22, Balance: 3000, },
        ]
      },
    },
  }
</script>